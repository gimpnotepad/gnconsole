#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
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
systeminfo | info about system
random [min] [max] | random number
color [num] | change console color
cls | clear screen
calc | calculator
browser | browser
ai | ai test
print [text] | output text
gncsa [numbers] | similar to print [text], but with numbers and support for GNCSA standard)"},
	{"on", "on"},
	{"info", "Information"},
	{"warn", "Warning"},
	{"err", "Error"},
	{"log:loaded", "Program loaded!"},
	{"log:nulllang", "No such language"},
	{"browser", R"(GimpNotepad Console Browser
All websites here start with the gncb prefix, not the https prefix!

It's important to remember this!

Popular websites:
gncb://gncb.run
gncb://max.run
gncb>)"},
	{"browser:gncbrun", R"(
	GNCB INTRODUCTION SITE

	This site was created to provide you 
	with a virtual browser that is not HTML!
)"},
	{"browser:maxrun", R"(
MAX.RUN
My cat's website

meow
)"},
	{"meow", "meow"},
};
std::map<std::string,std::string> de = {
	{"about", "Gimpnotizbuch-Konsole, 2026."},
	{"lang", "Sprache auswählen:"},
	{"help", R"(==== HELP ====
lang | Sprache ändern
exit | Programm beenden
help | Hilfe anzeigen
about | über Programm
systeminfo | Systeminformationen
random [min] [max] | Zufallszahl
color [Zahl] | Konsolenfarbe ändern
cls | Bildschirm löschen
calc | Kalkulator
browser | Browser
ai | KI-Test
print [Text] | Ausgabetext
gncsa [Zahlen] | Ähnlich wie print [Text], jedoch mit Zahlen und Unterstützung für den DSaGNK-Standard)"},
	{"on", "auf"},
	{"info", "Info"},
	{"warn", "Warnung"},
	{"err", "Fehler"},
	{"log:loaded", "Programm geladen!"},
	{"log:nulllang", "Keine solche Sprache"},
	{"browser", R"(GimpNotizbuch Konsolenbrowser
Alle Websites hier beginnen mit dem Präfix gncb, nicht mit https!

Das ist wichtig zu merken!

Beliebte Websites:
gncb://gncb.run
gncb://max.run
gncb>)"},
	{"browser:gncbrun", R"(
	GNKB EINFÜHRUNGSSEITE

	Diese Website wurde erstellt, 
	um Ihnen einen virtuellen Browser bereitzustellen,
	der kein HTML ist!
)"},
	{"browser:maxrun", R"(
MAX.RUN
Die Webseite meiner Katze

Miau
)"},
	{"meow", "Miau"},
};
std::map<std::string,std::string> ru = {
	{"about", "Консоль ГимпБлокнота, 2026."},
	{"lang", "Выбери язык:"},
	{"help", R"(==== HELP ====
lang | сменить язык
exit | выйти из программы
help | показать этот список
about | об этой программе
systeminfo | информация о системе
random [min] [max] | случайное число
color [num] | сменить цвет консоли
cls | очистить экран
calc | калькулятор
browser | браузер
ai | тест ии
print [text] | вывести текст
gncsa [numbers] | аналогично, что и print [text], но с числами и поддержкой стандарта САКГБ)"},
	{"on", "на"},
	{"info", "Информация"},
	{"warn", "Предупреждение"},
	{"err", "Ошибка"},
	{"log:loaded", "Программа загрузилась!"},
	{"log:nulllang", "Нету такого языка"},
	{"browser", R"(Браузер Консоли ГимпБлокнота
Все сайты здесь начинаются не с префикса https, 
а с префикса gncb! это важно запомнить!

Популярные сайты:
gncb://gncb.run
gncb://max.run
gncb>)"},
	{"browser:gncbrun", R"(
	САЙТ ОЗНАКОМЛЕНИЯ БКГБ
	
	Этот сайт сделан ради того, чтобы предоставить
	вам виртуальный браузер, который не является
	HTML!
)"},
	{"browser:maxrun", R"(
MAX.RUN
Сайт моего кота

мяу
)"},
	{"meow", "мяу"},
};

int lang = 0;
bool debug = 0;
std::string name = "gnc";
int color = 7;

const char en_l[] = {
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
};

const char* ru_l[] = {
	"А","Б","В","Г","Д","Е","Ё","Ж","З","И","Й","К","Л","М","Н","О","П","Р","С","Т","У","Ф","Х","Ц","Ч","Ш","Щ","Ъ","Ы","Ь","Э","Ю","Я",
	"а","б","в","г","д","е","ё","ж","з","и","й","к","л","м","н","о","п","р","с","т","у","ф","х","ц","ч","ш","щ","ъ","ы","ь","э","ю","я",
};

const char* de_l[] = {
	"Ä","Ö","Ü","ß",
	"ä","ö","ü","ß",
};

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

namespace ai {
	double sigmoid(double x) {
		return 1.0 / (1.0 + exp(-x));
	}

	double sigmoid_derivative(double x) {
		return x * (1.0 - x);
	}
	void train(double* in, int sn, double* exc, double* w1, double* w2, double* b1, double* b2, int inn, int hn, int outn, int ep, double lr) {
		for (int epoch = 0; epoch < ep; epoch++) {
			for (int i = 0; i<sn; i++) {
				double* px = in + i * inn;
				double* ex = exc + i * outn;
				double* h = new double[hn];
				for (int j = 0; j < hn; j++) {
					double sum = b1[j];
					for (int k = 0; k < inn; k++) sum += px[k] * w1[k*hn+j];
					h[j] = ai::sigmoid(sum);
				}
				double* out = new double[outn];
				for (int j = 0; j < outn; j++) {
					double sum = b2[j];
					for (int k = 0; k < hn; k++) sum += h[k] * w2[k*outn+j];
					out[j] = ai::sigmoid(sum);
				}
				double* d_out = new double[outn];
				for (int j = 0; j < outn; j++) {
					double err = ex[j] - out[j];
					d_out[j] = err * ai::sigmoid_derivative(out[j]);
					b2[j] += lr * d_out[j];
					for (int k = 0; k < hn; k++) w2[k*outn+j] += lr * d_out[j] * h[k];
				}
				for (int j = 0; j < hn; j++) {
					double err = 0;
					for (int k = 0; k < outn; k++) err += d_out[k] * w2[j*outn+k];
					double d_h = err * ai::sigmoid_derivative(h[j]);
					b1[j] += lr * d_h;
					for (int k = 0; k < inn; k++) w1[k*hn+j] += lr * d_h * px[k];
				}
				delete[] h;
				delete[] out;
				delete[] d_out;
			}
		}
	}

	int guess(double* p, double* w1, double* w2, double* b1, double* b2, int inn, int hn, int outn) {
		double* h = new double[hn];
		for (int j = 0; j < hn; j++) {
			double sum = b1[j];
			for (int k = 0; k < inn; k++) sum += p[k] * w1[k*hn+j];
			h[j] = ai::sigmoid(sum);
		}
		double* out = new double[outn];
		for (int j = 0; j < outn; j++) {
			double sum = b2[j];
			for (int k = 0; k < hn; k++) sum += h[k] * w2[k*outn+j];
			out[j] = ai::sigmoid(sum);
		}
		int result = 0;
		for (int i = 1; i < outn; i++) if (out[i] > out[result]) result = i;
		delete[] h;
		delete[] out;
		return result;
	}
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	std::filesystem::path setf = "settings.gnc";
	if (!std::filesystem::exists(setf)){
		std::ofstream setfo(setf);
		setfo << "debug=0" <<"\n"<< "lang=en" << "\n" << "color=7" << "\n";
	} else {
		std::ifstream setfi(setf);
		std::string l;
		char test1[] = "=>";
		char test2[] = " ";
		if (setfi) {
			while (std::getline(setfi,l)){
				if (debug) {
				printf("%s\n", log_message(l.c_str(), "DEBUG"));
					for (char c : l){
						printf("%s", log_message(std::to_string((int)(unsigned char)c).c_str(), "DEBUG:ARGUMENT"));
					}
					printf("\n");
				}
				if (l.rfind("\xFF\xBB\xBF", 0) == 0) l.erase(0,3);
				if (!l.empty() && l.back() == '\r') l.pop_back();
				if (l.empty()) continue;
				auto p = l.find('=');
				std::string d_p = std::to_string(p);
				if (debug) printf("%s\n", log_message(d_p.c_str(), "DEBUG:POS_OF_EQUAL"));
				if (p != std::string::npos){
					std::string k = l.substr(0,p);
					std::string v = l.substr(p+1);
					if (debug) printf("%s", log_message(k.c_str(), "DEBUG"));
					if (debug) printf("%s", log_message(v.c_str(), "DEBUG"));
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
					} else if (k == "color") {
						if (sscanf(v.c_str(), "%d", &color) == 1) {
							set_console_color(color);
						}
					}
				}
			}
		}
	}
	if (debug) printf("\n%s\n", log_message(findstr("log:loaded").c_str(), findstr("info").c_str()));
	printf("%s\n", findstr("about").c_str());
	char inp[1024];
	int randmin, randmax, num;
	double calc1, calc2;
	char calcop[8];
	char calcopm;
	char str[1024];
	while (true){
		printf("%s>", name.c_str());
		fgets(inp, sizeof(inp), stdin);
		inp[strcspn(inp, "\n")] = '\0';
		if (strcmp(inp, "lang") == 0){
			printf("%s",findstr("lang").c_str());
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			if (strcmp(inp, "en") == 0) {
				changef(setf,"lang=","lang=en");
				lang=0;			
			} else if (strcmp(inp, "de") == 0) {
				changef(setf,"lang=","lang=de");
				lang=1;
			} else if (strcmp(inp, "ru") == 0) {
				changef(setf,"lang=","lang=ru");
				lang=2;
			} else {
				if (debug) printf("%s", log_message(findstr("log:nulllang").c_str(),findstr("warn").c_str()));
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
		} else if (sscanf(inp, "random %d %d", &randmin, &randmax) == 2) {
			printf("%d\n", randomint(randmin, randmax));
		} else if (sscanf(inp, "color %d", &num) == 1) {
			changef(setf, "color=", "color="+std::to_string(num));
			color = num;
			set_console_color(num);
		} else if (strcmp(inp, "cls") == 0) {
			system("cls");
		} else if (strcmp(inp, "calc") == 0) {
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			if (sscanf(inp, "%lf %c %lf", &calc1, &calcopm, &calc2) == 3) {
				if (calcopm == '+') printf("%.6lf\n", calc1+calc2);
				else if (calcopm == '-') printf("%.6lf\n", calc1-calc2);
				else if (calcopm == '*') printf("%.6lf\n", calc1*calc2);
				else if (calcopm == '/') {
					if (calc2 != 0) {
						printf("%.6lf\n", calc1/calc2);
					} else { 
						printf("NaN\n");
					}
				} else if (calcopm == '^') printf("%.6lf\n", pow(calc1,calc2));
			} else if (sscanf(inp, "%s %lf %lf", calcop, &calc1, &calc2) == 3) {
				if (strcmp(calcop, "nrt") == 0) {
					if ((calc1<0 && (int)calc2 % 2 == 0) || calc2==0) {
						printf("NaN\n");
					} else {
						printf("%.6lf\n", pow(calc1, (1.0/calc2)));
					}
				}
			} else if (sscanf(inp, "%s %lf", calcop, &calc1) == 2) {
				if (strcmp(calcop, "ln") == 0) {
					if (calc1 <= 0) printf("0.000000\n");
					printf("%.6lf\n", log(calc1));
				} 
			}
		} else if (strcmp(inp, "browser") == 0) {
			printf("%s",findstr("browser").c_str());
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			if (strcmp(inp, "gncb://gncb.run")==0) {
				printf("%s",findstr("browser:gncbrun").c_str());
			} else if (strcmp(inp, "gncb://max.run") == 0) {
				printf("%s",findstr("browser:maxrun").c_str());
				printf("%s\n", log_message(findstr("meow").c_str(), "MEOW"));
			}
		} else if (strcmp(inp, "ai") == 0) {
			int inn = 25, hn = 8, outn = 4;
			double inputs_flat[] = {
				0,0,1,0,0, 0,1,0,1,0, 1,1,1,1,1, 1,0,0,0,1, 1,0,0,0,1, // A
				1,1,1,1,1, 1,0,0,1,0, 1,1,1,1,1, 1,0,0,1,0, 1,1,1,1,1, // B
				0,1,1,1,1, 1,0,0,0,0, 1,0,0,0,0, 1,0,0,0,0, 0,1,1,1,1, // C
				1,1,1,1,0, 1,0,0,0,1, 1,0,0,0,1, 1,0,0,0,1, 1,1,1,1,0, // D
			};
			double expected[] = {
				1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1,
			};
			double* w1 = new double[inn * hn];
			double* w2 = new double[hn * outn];
			double* b1 = new double[hn]();
			double* b2 = new double[outn]();
			srand(42);
			for (int i=0; i<inn*hn;i++) w1[i] = ((double)rand()/RAND_MAX)*2-1;
			for (int i=0; i<hn*outn;i++) w2[i] = ((double)rand()/RAND_MAX)*2-1;
			if (debug) printf("ai::train\n");
			ai::train(inputs_flat,4,expected,w1,w2,b1,b2,inn,hn,outn,10000,0.1);
			printf("%s", log_message("ai trained", "AI"));
			char letters[4] = {'A', 'B', 'C', 'D'};
			for (int i = 0; i < 4; i++) {
				if (debug) printf("ai::guess\n");
				int r = ai::guess(inputs_flat + i * inn,w1,w2,b1,b2,inn,hn,outn);
				printf("%s", log_message("ai guessed:", "AI"));
				if (debug) printf("num%d ", r);
				printf("%c => %c\n", letters[i], letters[r]);
			}
			printf("%s", log_message("ai tested", "AI"));
			delete[] w1; delete[] w2; delete[] b1; delete[] b2;
		} else if (sscanf(inp, "print %1023[^\n]", str) == 1) {
			printf("%s\n", str);
		} else if (sscanf(inp, "gncsa %1023[^\n]", str) == 1) {
			int num;
			char* ptr = str;
			while (sscanf(ptr, "%d", &num) == 1) {
				if (num == 0) printf(" ");
				else if (num >= 1 && num <= 26) printf("%c", 'A'+num-1);
				else if (num >= 27 && num <= 52) printf("%c", en_l[num-27]);
				else if (num >= 53 && num <= 118) printf("%s", ru_l[num-53]);
				else if (num >= 119 && num <= 126) printf("%s", de_l[num-119]);
				while (*ptr && *ptr != ' ') ptr++;
				while (*ptr == ' ') ptr++;
			}
			printf("\n");
		}
	}
}