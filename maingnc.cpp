#include <stdio.h>
#include <map>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <windows.h>
#include "gndll.h" // check on https://github.com/gimpnotepad/gndll/releases/

std::map<std::string,std::string> en = {
	{"about", "Gimpnotepad's Console, 2026."},
	{"lang", "Choose the language:"},
	{"help", R"(==== HELP ====
lang | change the language
exit | exit the program
help | show this list
about | about this program
systeminfo | info about system)"},
	{"on", "on"}
};
std::map<std::string,std::string> de = {
	{"about", "Gimpnotizbuch-Konsole, 2026."},
	{"lang", "Sprache auswählen:"},
	{"help", R"(==== HELP ====
lang | Sprache ändern
exit | Programm beenden
help | Hilfe anzeigen
about | über Programm
systeminfo | Systeminformationen)"},
	{"on", "auf"}
};
std::map<std::string,std::string> ru = {
	{"about", "Консоль ГимпБлокнота, 2026."},
	{"lang", "Выбери язык:"},
	{"help", R"(==== HELP ====
lang | сменить язык
exit | выйти из программы
help | показать этот список
about | об этой программе
systeminfo | информация о системе)"},
	{"on", "na"}
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
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
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
				printf("%s\n", l.c_str());
					for (char c : l){
						printf("%d ", (int)(unsigned char)c);
					}
					printf("\n");
				}
				if (l.rfind("\xFF\xBB\xBF", 0) == 0) l.erase(0,3);
				if (!l.empty() && l.back() == '\r') l.pop_back();
				if (l.empty()) continue;
				auto p = l.find('=');
				if (debug) printf("%d\n", p);
				if (p != std::string::npos){
					std::string k = l.substr(0,p);
					std::string v = l.substr(p+1);
					if (debug) printf("%s %s\n", k.c_str(), v.c_str());
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
	printf("%s\n", findstr("about").c_str());
	char inp[1024];
	while (true){
		printf("%s>", name.c_str());
		scanf("%1024s", &inp);
		if (strcmp(inp, "lang") == 0){
			printf("%s\n",findstr("lang").c_str());
			scanf("%2s", inp);
			if (strcmp(inp, "en") == 0) {
				changef(setf,"lang=","lang=en");
				lang=0;			
			} else if (strcmp(inp, "de") == 0) {
				changef(setf,"lang=","lang=de");
				lang=1;
			} else if (strcmp(inp, "ru") == 0) {
				changef(setf,"lang=","lang=ru");
				lang=2;
			}
		} else if (strcmp(inp, "exit") == 0) {
			return 0;
		} else if (strcmp(inp, "help") == 0) {
			printf("%s\n", findstr("help").c_str());
		} else if (strcmp(inp, "about") == 0) {
			printf("%s\n", findstr("about").c_str());
		} else if (inp[0] == '\0') {
			;
		} else if (strcmp(inp, "systeminfo") == 0) {
			printf("%s@%s %s %s %s\n", get_pc_name(), get_user_name(), findstr("on").c_str(), get_nt_ver(), get_sysarch());
		}
	}
}