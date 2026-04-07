#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <windows.h>

std::map<std::string,std::string> en = {
	{"about", "Gimpnotepad's Console, 2026."},
	{"lang", "Choose the language:"},
	{"help", R"(==== HELP ====
lang | change the language
exit | exit the program
help | show this list)"}
};
std::map<std::string,std::string> de = {
	{"about", "Gimpnotizbuch-Konsole, 2026."},
	{"lang", "Sprache aeuswahlen:"},
	{"help", R"(==== HELP ====
lang | Sprache aendern
exit | Programm beenden
help | Hilfe anzeigen)"}
};
std::map<std::string,std::string> ru = {
	{"about", "Konsol' gimpbloknota, 2026."},
	{"lang", "Vyberi yazik:"},
	{"help", R"(==== HELP ====
lang | smenit' yazik
exit | viyti s programmy
help | pokazat' etot spisok)"}
};

int lang = 0;
bool debug = 0;
std::string name = "gnc";

std::string findstr(std::string str){
	if (lang == 0) {
		auto i = en.find(str);
		if (i != en.end()){
			return i->second;		
		}
	} else if (lang == 1) {
		auto i = de.find(str);
		if (i != de.end()){
			return i->second;		
		}
	} else if (lang == 2) {
		auto i = ru.find(str);
		if (i != ru.end()){
			return i->second;		
		}
	}
	return "";
}

void changef(std::filesystem::path setf, std::string a, std::string b){
	std::ifstream setfi(setf);
	if (!std::filesystem::exists(setf)){
		return;
	}
	std::vector<std::string> lines;
	std::string l;
	while (std::getline(setfi, l)){
		if (l.find(a) == 0){
			l = b;
		}
		lines.push_back(l);
	}
	setfi.close();
	std::ofstream setfo(setf);
	for (const auto& l : lines){
		setfo << l << "\n";
	}
	setfo.close();
}

int main(){
	std::filesystem::path setf = "settings.gnc";
	if (!std::filesystem::exists(setf)){
		std::ofstream setfo(setf);
		setfo << "debug=0" <<"\n"<< "lang=en" << "\n";
	} else {
		std::ifstream setfi(setf);
		std::string l;
		if (setfi) {
			while (std::getline(setfi,l)){
				if (debug) {
				std::cout << l << "\n";
					for (char c : l){
						std::cout << (int)(unsigned char)c << " ";
					}
					std::cout << "\n";
				}
				if (l.rfind("\xFF\xBB\xBF", 0) == 0) l.erase(0,3);
				if (!l.empty() && l.back() == '\r') l.pop_back();
				if (l.empty()) continue;
				auto p = l.find('=');
				if (debug) std::cout << p << "\n";
				if (p != std::string::npos){
					std::string k = l.substr(0,p);
					std::string v = l.substr(p+1);
					if (debug) std::cout << k << " " << v << "\n";
					if (k == "lang") {
						if (v == "de") lang = 1;
						else if (v == "ru") lang = 2;
						else if (v == "en") lang = 0;
					} else if (k == "debug"){
						if (v == "1") debug = true;
						else if (v == "0") debug = false;
					} else if (k == "name") {
						if (!v.empty()) name = v;
						else name = "gnc";
					}
				}
			}
		}
	}
	std::cout << findstr("about") << "\n";
	std::string inp;
	while (true){
		std::cout << name << ">";
		std::getline(std::cin, inp);
		if (inp == "lang"){
			std::cout << findstr("lang");
			std::getline(std::cin, inp);
			if (inp == "en") {
				changef(setf,"lang=","lang=en");
				lang=0;			
			} else if (inp == "de") {
				changef(setf,"lang=","lang=de");
				lang=1;
			} else if (inp == "ru") {
				changef(setf,"lang=","lang=ru");
				lang=2;
			}
		} else if (inp == "exit") {
			return 0;
		} else if (inp == "help") {
			std::cout << findstr("help") << std::endl;
		}
	}
}