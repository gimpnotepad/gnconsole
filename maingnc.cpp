#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
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
gncsa [numbers] | similar to print [text], but with numbers and support for GNCSA standard
set [x] [num] | set x to value num
get [x] | get the value of variable x
savevar | save variables to a file
loadvar | load variables from a file
gnclk | GNCLK programming language (Files only)
bcalc | Bit calculator)"},
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
	{"notfound", "This program is not on GNConsole. (or the arguments are empty/incorrect/incomplete)"},
	{"choosefile","Choose the file by name:"}
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
gncsa [Zahlen] | Ähnlich wie print [Text], jedoch mit Zahlen und Unterstützung für den DSaGNK-Standard
set [x] [num] | Setze x den Wert num
get [x] | Hole den Wert der Variablen x
savevar | Speichere Variablen in einer Datei
loadvar | Lade Variablen aus einer Datei
gnclk | GNCLK-Programmiersprache (nur Dateien)
bcalc | Bitrechner)"},
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
	{"notfound", "Dieses Programm ist nicht in der Gimpnotizbuch-Konsole verfügbar. (oder die Argumente sind leer/falsch/unvollständig)"},
	{"choosefile","Datei anhand des Namens auswählen:"}
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
gncsa [numbers] | аналогично, что и print [text], но с числами и поддержкой стандарта САКГБ
set [x] [num] | поставить x со значением num
get [x] | получить значение переменной x
savevar | сохранить переменные в файл
loadvar | загрузить переменные из файла
gnclk | язык программирования GNCLK (Только файлы)
bcalc | битовой калькулятор)"},
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
	{"notfound", "Эта программа отсутствует в консоли ГимпБлокнота. (или аргументы пустые/неправильные/неполные)"},
	{"choosefile", "Выбери файл по названию:"}
};
std::map<std::string,std::string> gn = {
	{"about", "Gimpbłocnot-Klonse, 2026."},
	{"lang", "Crećy lengse:"},
	{"help", R"(==== HELP ====
lang | selsec lengse
exit | klos progem
help | widenswac helaps
about | ubund progem
systeminfo | systubund
random [min] [max] | raćen nomle
color [num] | crećy cólt klonse
cls | ske klonse
calc | kelkretor
browser | bruzwer
ai | lingin-sys tresna
print [text] | owe żdikt
gncsa [numbers] | pocoże print [text], no sle nomle ini typro dla GBKSL sendra
set [x] [num] | postaviżd x zo znacene num
get [x] | polutiżd znacene x
savevar | sokrani peremenie w fil
loadvar | zargine peremenie iz fil
gnclk | lengse kod GNCLK (tolke fils)
bcalc | bittjeżdekelkretor)"},
	{"on", "re"},
	{"info", "Nsew"},
	{"warn", "Loedar"},
	{"err", "Krans"},
	{"log:loaded", "Progem lons'd!"},
	{"log:nulllang", "Null'n lengse"},
	{"browser", R"(GimpBłocnot-Klonse Bruzwer
Wsyal wetis toz natzinaca sle gncb pleix, xorne https pleix!

To wazcne pomnite!

Luzvsie wetis:
gncb://gncb.run
gncb://max.run
gncb>)"},
	{"browser:gncbrun", R"(
	GBKB POMOZV WETIN

	To wetin by sozdwa dla te 
	sle vertne bruzwer ye xorne HTML!
)"},
	{"browser:maxrun", R"(
MAX.RUN
Mer kats wetin

muar
)"},
	{"meow", "muar"},
	{"notfound", "To progem xorne re GBKlonse. (ili argef pust/xornepravin/xornepoln)"},
	{"choosefile","Crećy fil po nazwa:"}
};

std::map<std::string,std::string> pl = {
{"about", "Konsola GimpNotatnik, 2026."},
{"lang", "Wybierz język:"},
{"help", R"(==== HELP ====
lang | zmień język
exit | zamknij program
help | pokaż tę listę
about | o tym programie
systeminfo | informacje o systemie
random [min] [max] | liczba losowa
color [num] | zmień kolor konsoli
cls | wyczyść ekran
calc | kalkulator
browser | przeglądarka
ai | test AI
print [text] | wyświetl tekst
gncsa [numbers] | to samo co print [text], ale z liczbami i obsługą standardu SAKGN
set [x] [liczba] | ustaw x na wartość num
get [x] | pobierz wartość zmiennej x
savevar | zapisz zmienne do pliku
loadvar | załaduj zmienne z pliku
gnclk | Język programowania GNCLK (tylko pliki)
bcalc | Kalkulator bitowy)"},
{"on", "na"},
{"info", "Informacje"},
{"warn", "Ostrzeżenie"},
{"err", "Błąd"},
{"log:loaded", "Program załadowany!"},
{"log:nulllang", "Brak takiego języka"},
{"browser", R"(Konsola GimpNotatnik przeglądarka
Wszystkie strony tutaj zaczynają się od prefiksu gncb, a nie prefiksu https,
warto o tym pamiętać!

Popularne strony:
gncb://gncb.run
gncb://max.run
gncb>)"},
{"browser:gncbrun", R"(
STRONA WPROWADZAJĄCA KGNP

Ta strona została stworzona, aby zapewnić
ci wirtualną przeglądarkę, która nie jest
HTML!
)"},
{"browser:maxrun", R"(
MAX.RUN
Strona mojego kota

miau
)"},
{"meow", "miau"},
{"notfound", "Ten program nie jest obecny w konsoli GimpNotatnik. (lub argumenty są pusty/niepoprawny/niekompletny)"},
{"choosefile","Wybierz plik według nazwy:"}
};

int lang = 0;
bool debug = 0;
std::string name = "gnc";
int color = 7;

std::vector<int> p = {0};
std::map<std::string, int> f = {};
bool gncsab = false;
bool logic = false;
int depth = 0;
int skip_depth = 0;
int pc_r;
int ctpc;
int func;
bool ferr = false;

std::map<std::string, int> varsd_gnclk;
std::map<std::string, std::string> varst_gnclk;

const char* sys_l[] = {
	"", ".", ",", "-", "+", "*", "/", "(", ")", "&", "^", "%", "$", "#", "\"", "'", "\\"
};

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

const char* pl_gn_l[] = {
	"Ą", "Ć", "Ę", "Ł", "Ń", "Ó", "Ś", "Ź", "Ż",
    "ą", "ć", "ę", "ł", "ń", "ó", "ś", "ź", "ż"
};

void calc(const char* inp) {
	double calc1, calc2;
	char calcop[8];
	char calcopm;
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
		} else if (strcmp(calcop, "log") == 0) {
			if (calc1 <= 0 || calc2 <= 0) {
				printf("0.000000\n");
			} else {
				printf("%.6lf\n", log(calc1)/log(calc2));
			}
		} else if (strcmp(calcop, "atan2") == 0) {
			printf("%.6lf\n", atan2(calc1,calc2));
		}
	} else if (sscanf(inp, "%s %lf", calcop, &calc1) == 2) {
		if (strcmp(calcop, "ln") == 0) {
			if (calc1 <= 0) printf("0.000000\n");
			printf("%.6lf\n", log(calc1));
		} else if (strcmp(calcop, "sin") == 0) {
			printf("%.6lf\n", sin(calc1));
		} else if (strcmp(calcop, "cos") == 0) {
			printf("%.6lf\n", cos(calc1));
		} else if (strcmp(calcop, "tg") == 0) {
			printf("%.6lf\n", tan(calc1));
		} else if (strcmp(calcop, "tan") == 0) {
			printf("%.6lf\n", tan(calc1));
		}  else if (strcmp(calcop, "asin") == 0) {
			printf("%.6lf\n", asin(calc1));
		} else if (strcmp(calcop, "acos") == 0) {
			printf("%.6lf\n", acos(calc1));
		} else if (strcmp(calcop, "atan") == 0) {
			printf("%.6lf\n", atan(calc1));
		}
	}
}

void gncsa(char* str) {
	int num;
	char* ptr = str;
	while (sscanf(ptr, "%d", &num) == 1) {
		if (num == 0) printf(" ");
		else if (num < 0 && num >= -16) printf("%s", sys_l[-num]);
		else if (num >= 1 && num <= 26) printf("%c", 'A'+num-1);
		else if (num >= 27 && num <= 52) printf("%c", en_l[num-27]);
		else if (num >= 53 && num <= 118) printf("%s", ru_l[num-53]);
		else if (num >= 119 && num <= 126) printf("%s", de_l[num-119]);
		else if (num >= 127 && num <= 144) printf("%s", pl_gn_l[num-127]);
		while (*ptr && *ptr != ' ') ptr++;
		while (*ptr == ' ') ptr++;
	}
	printf("\n");
}

void gnclk(const char* inp, int& pc) {
	char str[1024];
	char name[32];
	char n1[32];
	char n2[32];
	char n3[32];
	int vald;
	char valt[1024];
	char op;
	if (skip_depth == 0 && func == 0) {
		if (sscanf(inp, "print(\"%[^\"]\");", str) == 1) {
				printf("%s\n", str);
		} else if (sscanf(inp, "int %31[A-Za-z] = %d;", name, &vald) == 2) {
			if (varsd_gnclk.count(name)) printf("DefineError: this variable is defined\n");
			else varsd_gnclk[name] = vald;
		} else if (sscanf(inp, "txt %31[A-Za-z] = \"%[^\"]\";", name, valt) >= 2) {
			if (varst_gnclk.count(name)) printf("DefineError: this variable is defined\n");
			else varst_gnclk[name] = (strlen(valt) > 0) ? valt : "";
		} else if (sscanf(inp, "printd(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) printf("%d\n", varsd_gnclk[name]);
		} else if (sscanf(inp, "printt(%31[A-Za-z]);", name) == 1) {
			if (varst_gnclk.count(name)) printf("%s\n", varst_gnclk[name].c_str());
		} else if (sscanf(inp, "%31[A-Za-z] i= %d;", name, &vald) == 2) {
			if (varsd_gnclk.count(name)) varsd_gnclk[name] = vald;
			else printf("DefineError: this variable is not defined\n");
		} else if (sscanf(inp, "%31[A-Za-z] t= \"%[^\"]\";", name, &valt) == 2) {
			if (varst_gnclk.count(name)) varst_gnclk[name] = valt;
			else printf("DefineError: this variable is not defined\n");
		} else if (strcmp(inp, "$use gncsa") == 0) {
			gncsab = true;
		} else if (sscanf(inp, "gncsa(%1023[0-9 ]);", str) == 1) {
			if (gncsab) gncsa(str);
		} else if (sscanf(inp, "cmpd(%31[A-Za-z],%31[A-Za-z]);", n1, n2) == 2) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) logic = (varsd_gnclk[n1] == varsd_gnclk[n2]);
		} else if (sscanf(inp, "cmpt(%31[A-Za-z],%31[A-Za-z]);", n1, n2) == 2) {
			if (varst_gnclk.count(n1) && varst_gnclk.count(n2)) logic = (varst_gnclk[n1] == varst_gnclk[n2]);
		} else if (strcmp(inp, "printl();") == 0) {
			printf("%d\n", logic);
		} else if (strncmp(inp, "ifl", 3) == 0) {
			p.push_back(logic ? 0 : 1); 
			if (!logic) skip_depth = 1;
		} else if (strncmp(inp, "ifnl", 3) == 0) { 
			p.push_back(!logic ? 0 : 1);
			if (logic) skip_depth = 1;
			depth++;
		} else if(sscanf(inp, "func %31[A-Za-z]", name) == 1) {
			if (func == 1) {
				printf("FuncError: Function in Function\n");
				ferr = true;
				return;
			}
			if (pc != ctpc) {
			    skip_depth = 1;
			    func = 1;
			} else {
				skip_depth = 0;
			    func = 0;
			}
			if (!f.count(name)) f[name] = pc;
		} else if (sscanf(inp, "callfunc(%31[A-Za-z]);", name) == 1) {
			if (f.count(name)) {
				pc_r = pc;
				ctpc = f[name];
		    	pc = f[name];
				skip_depth = 0;
				func = 0;
			}
		} else if (strncmp(inp, "endfunc", 7) == 0 && skip_depth == 0) {
			if (pc_r != -1) {
				pc = pc_r;
				pc_r = -1;
				ctpc = -1;
				depth = 0;
			}
			func = 0;
			skip_depth = 0;
		} else if (sscanf(inp, "inputt(%31[A-Za-z]);", name) == 1) {
			if (varst_gnclk.count(name)) {
				char inw[1024];
        		while (fgets(inw, sizeof(inw), stdin)) {
            		inw[strcspn(inw, "\n")] = 0;
            		if (strlen(inw) > 0) {
       		         	varst_gnclk[name] = inw;
        	        	break;
        	    	}
        		}
			}
		} else if (sscanf(inp, "inputd(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) {
				char in[1024];
				if (fgets(in, sizeof(in), stdin)) {
					int t_v;
					if (sscanf(in, "%d", &t_v) == 1) {
						varsd_gnclk[name] = t_v;
					}
				}
			}
		} else if(sscanf(inp, "calc(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2) && varsd_gnclk.count(n3)) {
				if (op == '+') varsd_gnclk[n3] = varsd_gnclk[n1] + varsd_gnclk[n2];
				else if (op == '-') varsd_gnclk[n3] = varsd_gnclk[n1] - varsd_gnclk[n2];
				else if (op == '*') varsd_gnclk[n3] = varsd_gnclk[n1] * varsd_gnclk[n2];
				else if (op == '/' && varsd_gnclk[n2] > 0) varsd_gnclk[n3] = varsd_gnclk[n1] / varsd_gnclk[n2];
				else if (op == '^') varsd_gnclk[n3] = std::pow(varsd_gnclk[n1],varsd_gnclk[n2]);
				else if (op == '#' && varsd_gnclk[n1]>=0 && varsd_gnclk[n2]%2!=0) varsd_gnclk[n3] = std::pow(varsd_gnclk[n1], 1/varsd_gnclk[n2]);
				else if (op == '&' && varsd_gnclk[n1]>0 && varsd_gnclk[n2]>0) varsd_gnclk[n3] = log(varsd_gnclk[n1])/log(varsd_gnclk[n2]); 
			}
		}
	}
	if (strncmp(inp, "stp", 3) == 0 && func == 0) {
		if (depth>0) { 
			depth--;
			if (!p.empty()) {
				p.pop_back();
				if (depth<p.size()) skip_depth = p[depth];
				else skip_depth = 0;
			} else skip_depth = 0;
		} else skip_depth = 0;
	} else if (strncmp(inp, "endfunc", 7) == 0 && skip_depth == 1 && func == 1) {
		func = 0;
		skip_depth = 0;
	}
}

void errorhappened(const char* err) {
	set_console_color(64);
	system("cls");
	printf("%s", err);
	while (true) {}
}

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
	} else if (lang == 3) {
		auto i = gn.find(str);
		if (i != gn.end()){
			return i->second;		
		}
	} else if (lang == 4) {
		auto i = pl.find(str);
		if (i != pl.end()){
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

void save_variables(const std::map<std::string, double>& vars, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        if (debug) printf("%s", log_message("file:cannotread", findstr("err").c_str()));
        return;
    }
    for (const auto& [name, val] : vars) {
        fprintf(f, "%s=%g\n", name.c_str(), val);
    }
    fclose(f);
    if (debug) printf("Saved %s\n", filename);
}

void load_variables(std::map<std::string, double>& vars, const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        if (debug) printf("%s", log_message("file:null\n", findstr("warn").c_str()));
        return;
    }
    char line[128];
    char key[32];
    double val;
    while (fgets(line, sizeof(line), f)) {
        if (sscanf(line, " %31[a-zA-Z0-9] = %lf", key, &val) == 2) {
            vars[key] = val;
        }
    }
    fclose(f);
    if (debug) printf("Loaded from %s\n", filename);
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

char* program[65536];
int total_lines = 0;

void load_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("%s\n", log_message(filename, "ERROR:NOTOPEN"));
        return;
    }
    char buffer[1100];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\r\n")] = 0;
        program[total_lines] = strdup(buffer);
        total_lines++;
    }
    fclose(file);
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	std::map<std::string, double> vars;
	std::filesystem::path setf = "settings.gnc";
	if (!std::filesystem::exists(setf)){
		std::ofstream setfo(setf);
		setfo << "debug=0" <<"\n"<< "lang=en" << "\n" << "color=7" << "\n";
	} else {
		std::ifstream setfi(setf);
		std::string l;
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
						else if (v == "gn") lang = 3;
						else if (v == "pl") lang = 4;
						else if (v == "en") lang = 0;
					} else if (k == "debug"){
						if (v == "1") debug = true;
						else if (v == "0") debug = false;
						else errorhappened("ERROR:DEBUG_OR_NOT");
					} else if (k == "name") {
						if (!v.empty()) name = v;
						else name = "gnc";
					} else if (k == "color") {
						if (sscanf(v.c_str(), "%d", &color) == 1) {
							set_console_color(color);
						} else {
							errorhappened("ERROR:INCORRECT_COLOR");
						}
					}
				}
			}
		}
	}
	load_variables(vars, "vars.gnc");
	if (debug) printf("\n%s\n", log_message(findstr("log:loaded").c_str(), findstr("info").c_str()));
	printf("%s\n", findstr("about").c_str());
	char inp[1024];
	int randmin, randmax, num, num1, num2;
	char str[1024];
	double numv;
	char varn[32];
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
			} else if (strcmp(inp, "gn") == 0) {
				changef(setf,"lang=","lang=gn");
				lang=3;
			} else if (strcmp(inp, "pl") == 0) {
				changef(setf,"lang=","lang=pl");
				lang=4;
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
			printf("calc>");
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			calc(inp);
		} else if (strcmp(inp, "browser") == 0) {
			printf("%s",findstr("browser").c_str());
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			if (strcmp(inp, "gncb://gncb.run")==0) {
				printf("%s",findstr("browser:gncbrun").c_str());
			} else if (strcmp(inp, "gncb://max.run") == 0) {
				printf("%s",findstr("browser:maxrun").c_str());
				printf("%s\n", log_message(findstr("meow").c_str(), "MEOW"));
				std::this_thread::sleep_for(std::chrono::seconds(5));
				errorhappened("meow meow meow meow meow \nmeow meow meow meow meow \nmeow meow meow meow meow \nmeow meow meow meow meow \nmeow meow meow meow meow");
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
			gncsa(str);
		} else if (sscanf(inp, "set %31[a-zA-Z0-9] %lf", varn, &numv) == 2) {
			vars[varn] = numv;
		} else if (sscanf(inp, "get %31[a-zA-Z0-9]", varn) == 1) {
			if (vars.count(varn)) printf("%lf\n", vars[varn]);
			else printf("undefined\n");
		} else if (strcmp(inp, "savevar") == 0) {
			save_variables(vars, "vars.gnc");
		} else if (strcmp(inp, "loadvar") == 0) {
			load_variables(vars, "vars.gnc");
		} else if (strcmp(inp, "bcalc") == 0){
			printf("bcalc>");
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			char calcopm;
			if (sscanf(inp, "%d %c %d", &num1, &calcopm, &num2) == 3) {
				if (calcopm == '^') printf("%d\n",num1^num2);
				else if (calcopm == '>') printf("%d\n",num1>>num2);
				else if (calcopm == '<') printf("%d\n",num1<<num2);
				else if (calcopm == '&') printf("%d\n",num1&num2);
				else if (calcopm == '|') printf("%d\n",num1|num2);
			} else if (sscanf(inp, "%c%d", &calcopm, &num1) == 2) {
				if (calcopm == '!') printf("%d", !num1);
			}
		} else if (sscanf(inp, "hexv %s", &varn) == 1) {
			if (vars.count(varn)) printf("%X\n", vars[varn]);
		} else if (sscanf(inp, "hex %d", &num) == 1) {
			printf("%X\n", num);
		} else if (strcmp(inp, "gnclk") == 0) {
			printf("%s\n", findstr("choosefile").c_str());
			fgets(inp, sizeof(inp), stdin);
			inp[strcspn(inp, "\n")] = '\0';
			char filename[1024];
			snprintf(filename, sizeof(filename), "%s.gnclk", inp);
			for (int i = 0; i<total_lines; i++){
				if (program[i] != NULL) {
					free(program[i]);
					program[i] = NULL;
				}
			}
			total_lines = 0;
			skip_depth = 0;
			varsd_gnclk.clear();
			varst_gnclk.clear();
			load_file(filename);
			int pc = 0;
			while (pc < total_lines) {
				if (!ferr) {
    				gnclk(program[pc], pc);
    			}
    			pc++;
    		}
    		if (depth != 0) {
    			printf("Stopped on depth No. %d\n", depth);
			}
			ferr = false;
		} else {
			printf("%s", log_message(findstr("notfound").c_str(), findstr("err").c_str()));
		}
	}
}