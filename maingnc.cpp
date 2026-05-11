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
bcalc | Bit calculator
hex [num]
hexv [x])"},
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
bcalc | Bitrechner
hex [num]
hexv [x])"},
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
bcalc | битовой калькулятор
hex [num]
hexv [x])"},
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
bcalc | bittjeżdekelkretor
hex [num]
hexv [x])"},
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
bcalc | Kalkulator bitowy
hex [num]
hexv [x])"},
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
std::map<std::string,std::string> what = {
	{"about", "Консоль меня из 2026"},
	{"lang", "Ну блиииииииин! не сменяй пж! Хотя ладно, давай, \nпиши язык:"},
	{"help", R"(==== HELP ====
lang | не надо пжпжпжпжпж
exit | пока
help | какой-то список
about | ну и что
systeminfo | докажи, что ты с винды 7, как разработчик
random [min] [max] | число лол
color [num] | краска
cls | ща почищу
calc | читы для егэ
browser | тупой текст
ai | иишка реальная гпт 100% официальная не шутка скачать бесплатно без регистрации и смс с вирусами
print [text] | пукнуть в консоль с помощью текст
gncsa [numbers] | херня эта лучше print
set [x] [num] | переменные 
get [x] | какашка
savevar | мб попробовать создать свой файл для gnclk
loadvar | что
gnclk | дебильный яп
bcalc | суперчиты для информатики
hexv [x]
hex [num])"},
	{"on", "в"},
	{"info", "Фигня"},
	{"warn", "Щас покакаю"},
	{"err", "Насрал в раковину"},
	{"log:loaded", "Программа насрала в раковину"},
	{"log:nulllang", "Фухххх"},
	{"browser", R"(Тупой браузер
https херня, лучше использовать gncb

Хайповые сайты:
gncb://gncb.run
gncb://max.run
gncb>)"},
	{"browser:gncbrun", R"(
	САЙТ ОЗНАКОМЛЕНИЯ ЧЕГО-ТО
	
	HTML фигня полная
	используй консоль
)"},
	{"browser:maxrun", R"(
MAX.RUN
Сайт моего говнюка

мяу
)"},
	{"meow", "мяу"},
	{"notfound", "Что ты несёшь вообще"},
	{"choosefile", "Хммммммммммм:"}
};

int lang = 0;
bool debug = 0;
std::string name = "gnc";
int color = 7;
std::map<std::string, double> vars;

std::vector<int> p = {0};
std::map<std::string, int> f = {};
bool gncsab = false;
bool gnsys = false;
bool ll = false;
bool logic = false;
int depth = 0;
int skip_depth = 0;
int pc_r;
int ctpc;
int func;
bool ferr = false;
char* program[65536];
int total_lines = 0;

std::map<std::string, int> varsd_gnclk;
std::map<std::string, std::string> varst_gnclk;
std::map<std::string, bool> varsb_gnclk;
std::map<std::string, double> varsdbl_gnclk;
std::map<std::string, unsigned int> varsdu_gnclk;
std::map<std::string, long long int> varsll_gnclk;
std::map<std::string, uint64_t> varsllu_gnclk;

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
	} else if (lang == 5) {
		auto i = what.find(str);
		if (i != what.end()) return i->second;
	}
	return "";
}

std::string p2dp(std::string str) {
	std::string result;
	for (char c : str) {
		if (c == '%') result += "%%";
		else result += c;
	}
	return result;
}

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
}

void gnclk(const char* inp, int& pc) {
	char str[1024];
	char name[32];
	char n1[32];
	char n2[32];
	char n3[32];
	char n4[32];
	char nout[32];
	char nin[32];
	char s1[1024];
	char s2[1024];
	int vald;
	char valt[1024];
	int valb;
	unsigned int valdu;
	long long int valll;
	long long unsigned valllu;
	char op;
	char tail[1024];
	double valdbl;
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
	} else if (skip_depth == 0 && func == 0) {
		if (sscanf(inp, "print(\"%[^\"]\");", str) == 1) {
				printf("%s", str);
		} else if (sscanf(inp, "int %31[A-Za-z] = %d;", name, &vald) == 2) {
			if (varsd_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else varsd_gnclk[name] = vald;
		} else if (sscanf(inp, "txt %31[A-Za-z] = \"%[^\"]\";", name, valt) >= 2) {
			if (varst_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else varst_gnclk[name] = (strlen(valt) > 0) ? valt : "";
		} else if (sscanf(inp, "bool %31[A-Za-z] = %1[01];", name, &valb) >= 2) {
			if (varsb_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else varsb_gnclk[name] = valb;
		} else if (sscanf(inp, "dbl %31[A-Za-z] = %lf;", name, &valdbl) >= 2) {
			if (varsdbl_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else varsdbl_gnclk[name] = valdbl;
		} else if (sscanf(inp, "uint %31[A-Za-z] = %u;", name, &valdu) == 2) {
			if (varsdu_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else varsdu_gnclk[name] = valdu;
		} else if (sscanf(inp, "ll %31[A-Za-z] = %lld;", name, &valll) == 2) {
			if (varsll_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else if (!ll) {
				printf("DefineError: use $use ll to continue.");
				ferr = true;
				return;
			}
			else varsll_gnclk[name] = valll;
		} else if (sscanf(inp, "llu %31[A-Za-z] = %llu;", name, &valllu) == 2) {
			if (varsllu_gnclk.count(name)) {
				printf("DefineError: this variable is defined\n");
				ferr = true;
				return;
			}
			else if (!ll) {
				printf("DefineError: use $use ll to continue.");
				ferr = true;
				return;
			}
			else varsllu_gnclk[name] = valllu;
		} else if (sscanf(inp, "printd(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) printf("%d", varsd_gnclk[name]);
		} else if (sscanf(inp, "printll(%31[A-Za-z]);", name) == 1) {
			if (varsll_gnclk.count(name)) printf("%lld", varsll_gnclk[name]);
			else if (!ll) {
				printf("OutputError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "printllu(%31[A-Za-z]);", name) == 1) {
			if (varsllu_gnclk.count(name)) printf("%llu", varsllu_gnclk[name]);
			else if (!ll) {
				printf("OutputError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "printdu(%31[A-Za-z]);", name) == 1) {
			if (varsdu_gnclk.count(name)) printf("%u", varsdu_gnclk[name]);
		} else if (sscanf(inp, "printt(%31[A-Za-z]);", name) == 1) {
			if (varst_gnclk.count(name)) printf("%s", varst_gnclk[name].c_str());
		} else if (sscanf(inp, "printdbl(%31[A-Za-z]);", name) == 1) {
			if (varsdbl_gnclk.count(name)) printf("%lf", varsdbl_gnclk[name]);
		} else if (strncmp(inp, "lf();",10) == 0) {
			printf("\n");
		} else if (sscanf(inp, "%31[A-Za-z] i= %d;", name, &vald) == 2) {
			if (varsd_gnclk.count(name)) varsd_gnclk[name] = vald;
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "%31[A-Za-z] t= \"%[^\"]\";", name, &valt) == 2) {
			if (varst_gnclk.count(name)) varst_gnclk[name] = valt;
			else {
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "%31[A-Za-z] b= %1[01];", name, &valb) == 2) {
			if (varsb_gnclk.count(name)) varsb_gnclk[name] = valb;
			else {
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "%31[A-Za-z] dbl= %lf;", name, &valdbl) == 2) {
			if (varsdbl_gnclk.count(name)) varsdbl_gnclk[name] = vald;
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "%31[A-Za-z] ui= %d;", name, &valdu) == 2) {
			if (varsdu_gnclk.count(name)) varsdu_gnclk[name] = valdu;
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "%31[A-Za-z] ll= %lld;", name, &valll) == 2) {
			if (varsll_gnclk.count(name)) varsll_gnclk[name] = valll;
			else if (!ll) {
				printf("DefineError: use $use ll to continue.");
				ferr = true;
				return;
			}
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "%31[A-Za-z] llu= %llu;", name, &valllu) == 2) {
			if (varsllu_gnclk.count(name)) varsllu_gnclk[name] = valllu;
			else if (!ll) {
				printf("DefineError: use $use ll to continue.");
				ferr = true;
				return;
			}
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "inc(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) varsd_gnclk[name]++;
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "sub(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) varsd_gnclk[name]--;
			else { 
				printf("DefineError: this variable is not defined\n");
				ferr = true;
				return;
			}
		} else if (strcmp(inp, "$use gncsa") == 0) {
			gncsab = true;
		} else if (sscanf(inp, "gncsa(%1023[0-9 ]);", str) == 1) {
			if (gncsab) gncsa(str);
		} else if (sscanf(inp, "cmpd(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) logic = (varsd_gnclk[n1] == varsd_gnclk[n2]);
		} else if (sscanf(inp, "cmpll(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsll_gnclk.count(n1) && varsll_gnclk.count(n2)) logic = (varsll_gnclk[n1] == varsll_gnclk[n2]);
			else if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "cmpllu(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsllu_gnclk.count(n1) && varsllu_gnclk.count(n2)) logic = (varsllu_gnclk[n1] == varsllu_gnclk[n2]);
			else if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "cmpdu(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2)) logic = (varsdu_gnclk[n1] == varsdu_gnclk[n2]);
		} else if (sscanf(inp, "cmpt(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varst_gnclk.count(n1) && varst_gnclk.count(n2)) logic = (varst_gnclk[n1] == varst_gnclk[n2]);
		} else if (sscanf(inp, "cmpdbl(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdbl_gnclk.count(n1) && varsdbl_gnclk.count(n2)) logic = (varsdbl_gnclk[n1] == varsdbl_gnclk[n2]);
		} else if (sscanf(inp, "setl(%31[A-Za-z]);", n1) == 1) {
			if (varsb_gnclk.count(n1)) logic = varsb_gnclk[n1];
		} else if (sscanf(inp, "cmpdb(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) logic = (varsd_gnclk[n1] > varsd_gnclk[n2]);
		} else if (sscanf(inp, "cmpllb(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsll_gnclk.count(n1) && varsll_gnclk.count(n2)) logic = (varsll_gnclk[n1] > varsll_gnclk[n2]);
			else if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "cmpdub(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2)) logic = (varsdu_gnclk[n1] > varsdu_gnclk[n2]);
		} else if (sscanf(inp, "cmpdl(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) logic = (varsd_gnclk[n1] < varsd_gnclk[n2]);
		} else if (sscanf(inp, "cmplll(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsll_gnclk.count(n1) && varsll_gnclk.count(n2)) logic = (varsll_gnclk[n1] < varsll_gnclk[n2]);
			else if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "cmpdul(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2)) logic = (varsdu_gnclk[n1] < varsdu_gnclk[n2]);
		} else if (sscanf(inp, "cmpdblb(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdbl_gnclk.count(n1) && varsdbl_gnclk.count(n2)) logic = (varsdbl_gnclk[n1] > varsdbl_gnclk[n2]);
		} else if (sscanf(inp, "cmpdbll(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdbl_gnclk.count(n1) && varsdbl_gnclk.count(n2)) logic = (varsdbl_gnclk[n1] < varsdbl_gnclk[n2]);
		} else if (sscanf(inp, "cmpllul(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsllu_gnclk.count(n1) && varsllu_gnclk.count(n2)) logic = (varsllu_gnclk[n1] < varsllu_gnclk[n2]);
			else if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "cmpllub(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsllu_gnclk.count(n1) && varsllu_gnclk.count(n2)) logic = (varsllu_gnclk[n1] > varsllu_gnclk[n2]);
			else if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (strcmp(inp, "printl();") == 0) {
			printf("%d", logic);
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
		} else if (sscanf(inp, "inputll(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) {
				char in[1024];
				if (fgets(in, sizeof(in), stdin)) {
					long long int t_v;
					if (sscanf(in, "%lld", &t_v) == 1) {
						varsll_gnclk[name] = t_v;
					}
				}
			} else if (!ll) {
				printf("InputError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "inputdu(%31[A-Za-z]);", name) == 1) {
			if (varsdu_gnclk.count(name)) {
				char in[1024];
				if (fgets(in, sizeof(in), stdin)) {
					unsigned int t_v;
					if (sscanf(in, "%u", &t_v) == 1) {
						varsdu_gnclk[name] = t_v;
					}
				}
			}
		} else if (sscanf(inp, "inputdbl(%31[A-Za-z]);", name) == 1) {
			if (varsdbl_gnclk.count(name)) {
				char in[1024];
				if (fgets(in, sizeof(in), stdin)) {
					double t_v;
					if (sscanf(in, "%lf", &t_v) == 1) {
						varsdbl_gnclk[name] = t_v;
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
				else if (op == '%' && varsd_gnclk[n2]>0) varsd_gnclk[n3] = varsd_gnclk[n1] % varsd_gnclk[n2];
			}
		} else if(sscanf(inp, "calcu(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2) && varsdu_gnclk.count(n3)) {
				if (op == '+') varsdu_gnclk[n3] = varsdu_gnclk[n1] + varsdu_gnclk[n2];
				else if (op == '-') varsdu_gnclk[n3] = varsdu_gnclk[n1] - varsdu_gnclk[n2];
				else if (op == '*') varsdu_gnclk[n3] = varsdu_gnclk[n1] * varsdu_gnclk[n2];
				else if (op == '/' && varsd_gnclk[n2] > 0) varsdu_gnclk[n3] = varsdu_gnclk[n1] / varsdu_gnclk[n2];
				else if (op == '^') varsdu_gnclk[n3] = std::pow(varsdu_gnclk[n1],varsdu_gnclk[n2]);
				else if (op == '#' && varsdu_gnclk[n1]>=0 && varsdu_gnclk[n2]%2!=0) varsdu_gnclk[n3] = std::pow(varsdu_gnclk[n1], 1/varsdu_gnclk[n2]);
				else if (op == '&' && varsdu_gnclk[n1]>0 && varsdu_gnclk[n2]>0) varsdu_gnclk[n3] = log(varsdu_gnclk[n1])/log(varsdu_gnclk[n2]); 
				else if (op == '%' && varsdu_gnclk[n2]>0) varsdu_gnclk[n3] = varsdu_gnclk[n1] % varsdu_gnclk[n2];
			}
		} else if(sscanf(inp, "calcll(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (ll && varsll_gnclk.count(n1) && varsll_gnclk.count(n2) && varsll_gnclk.count(n3)) {
				if (op == '+') varsll_gnclk[n3] = varsll_gnclk[n1] + varsll_gnclk[n2];
				else if (op == '-') varsll_gnclk[n3] = varsll_gnclk[n1] - varsll_gnclk[n2];
				else if (op == '*') varsll_gnclk[n3] = varsll_gnclk[n1] * varsll_gnclk[n2];
				else if (op == '/' && varsll_gnclk[n2] > 0) varsll_gnclk[n3] = varsll_gnclk[n1] / varsll_gnclk[n2];
				else if (op == '^') varsll_gnclk[n3] = std::pow(varsll_gnclk[n1],varsll_gnclk[n2]);
				else if (op == '#' && varsll_gnclk[n1]>=0 && varsll_gnclk[n2]%2!=0) varsll_gnclk[n3] = std::pow(varsll_gnclk[n1], 1/varsll_gnclk[n2]);
				else if (op == '&' && varsll_gnclk[n1]>0 && varsd_gnclk[n2]>0) varsll_gnclk[n3] = log(varsll_gnclk[n1])/log(varsll_gnclk[n2]); 
				else if (op == '%' && varsll_gnclk[n2]>0) varsll_gnclk[n3] = varsll_gnclk[n1] % varsll_gnclk[n2];
			} else if (!ll) {
				printf("CalcError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if(sscanf(inp, "calcllu(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (ll && varsllu_gnclk.count(n1) && varsllu_gnclk.count(n2) && varsllu_gnclk.count(n3)) {
				if (op == '+') varsllu_gnclk[n3] = varsllu_gnclk[n1] + varsllu_gnclk[n2];
				else if (op == '-') varsllu_gnclk[n3] = varsllu_gnclk[n1] - varsllu_gnclk[n2];
				else if (op == '*') varsllu_gnclk[n3] = varsllu_gnclk[n1] * varsllu_gnclk[n2];
				else if (op == '/' && varsllu_gnclk[n2] > 0) varsllu_gnclk[n3] = varsllu_gnclk[n1] / varsllu_gnclk[n2];
				else if (op == '^') varsllu_gnclk[n3] = std::pow(varsllu_gnclk[n1],varsllu_gnclk[n2]);
				else if (op == '#' && varsllu_gnclk[n1]>=0 && varsllu_gnclk[n2]%2!=0) varsllu_gnclk[n3] = std::pow(varsllu_gnclk[n1], 1/varsllu_gnclk[n2]);
				else if (op == '&' && varsllu_gnclk[n1]>0 && varsdu_gnclk[n2]>0) varsllu_gnclk[n3] = log(varsllu_gnclk[n1])/log(varsllu_gnclk[n2]); 
				else if (op == '%' && varsllu_gnclk[n2]>0) varsllu_gnclk[n3] = varsllu_gnclk[n1] % varsllu_gnclk[n2];
			} else if (!ll) {
				printf("CalcError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if(sscanf(inp, "calcdbl(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsdbl_gnclk.count(n1) && varsdbl_gnclk.count(n2) && varsdbl_gnclk.count(n3)) {
				if (op == '+') varsdbl_gnclk[n3] = varsdbl_gnclk[n1] + varsdbl_gnclk[n2];
				else if (op == '-') varsdbl_gnclk[n3] = varsdbl_gnclk[n1] - varsdbl_gnclk[n2];
				else if (op == '*') varsdbl_gnclk[n3] = varsdbl_gnclk[n1] * varsdbl_gnclk[n2];
				else if (op == '/' && varsdbl_gnclk[n2] > 0) varsdbl_gnclk[n3] = varsdbl_gnclk[n1] / varsdbl_gnclk[n2];
				else if (op == '^') varsdbl_gnclk[n3] = std::pow(varsdbl_gnclk[n1],varsdbl_gnclk[n2]);
				else if (op == '#' && varsdbl_gnclk[n1]>=0 && fmod(varsdbl_gnclk[n2], 2.0) != 0.0) varsdbl_gnclk[n3] = std::pow(varsdbl_gnclk[n1], 1/varsdbl_gnclk[n2]);
				else if (op == '&' && varsdbl_gnclk[n1]>0 && varsdbl_gnclk[n2]>0) varsdbl_gnclk[n3] = log(varsdbl_gnclk[n1])/log(varsdbl_gnclk[n2]); 
				else if (op == '%' && varsdbl_gnclk[n2]>0) varsdbl_gnclk[n3] = fmod(varsdbl_gnclk[n1],varsdbl_gnclk[n2]);
			}
		} else if(sscanf(inp, "rnd(%31[A-Za-z], %31[A-Za-z]) -> %31[A-Za-z];", n1, n2, n3) == 3) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) { 
				varsd_gnclk[n3] = randomint(varsd_gnclk[n1], varsd_gnclk[n2]);
			}
		} else if(sscanf(inp, "jmp(%d);", &vald) == 1) {
			int ti = vald-1;
			int d = abs(ti-pc);
			if (d>50 || ti<0 || ti>=total_lines) {
				printf("JumpError: i can't jump too far");
			} else {
				pc = ti-1;
				depth = 0;
				skip_depth = 0;
			}
		} else if (strncmp(inp, "ferr();", 7) == 0) {
			ferr = true;
			return;
		} else if (strncmp(inp, "$use gnsys", 10) == 0) {
			gnsys = true;
		} else if (strncmp(inp, "$use ll", 7) == 0) {
			ll = true;
		} else if (strncmp(inp, "cls();", 6) == 0) {
			if (gnsys) system("cls");
		} else if (sscanf(inp, "color(%d);", &vald) == 1) {
			if (gnsys) set_console_color(vald);
		} else if (sscanf(inp, "colord(%31[A-Za-z]);", name) == 1) {
			if (gnsys && varsd_gnclk.count(name)) set_console_color(varsd_gnclk[name]);
		} else if (sscanf(inp, "iss(%31[A-Za-z], \"%1023[^\"]\", \"%1023[^\"]\", %31[A-Za-z], %31[A-Za-z]) -> %31[A-Za-z], %31[A-Za-z];", n1, s1, s2, n2, n3, nout, nin) == 7) {
			if (varst_gnclk.count(n1)) {
				std::string s = varst_gnclk[n1];
				std::string se1 = s1;
				std::string se2 = s2;
				if (se2 == "NULL") se2 = "";
				size_t pos1 = s.find(se1);
				if (pos1 != std::string::npos) {
					varst_gnclk[n2] = s.substr(0,pos1);
					if (!se2.empty()) {
						size_t ss2 = pos1 + se1.length();
						size_t pos2 = s.find(se2, ss2);
						if (pos2 != std::string::npos) {
							varst_gnclk[n3] = s.substr(ss2, pos2-ss2);
							varst_gnclk[nout] = s.substr(pos2+se2.length());
							varsd_gnclk[nin] = 2;
						} else {
							varst_gnclk[n3] = s.substr(ss2);
							varsd_gnclk[nin] = 1;
						}
					} else {
						varst_gnclk[n3] = s.substr(pos1+se1.length());
						varsd_gnclk[nin] = 1;
					}
				} else { 
					varsd_gnclk[nin] = 0;
				}
			}
		} else if (sscanf(inp, "txt2int(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			int b;
			if (sscanf(varst_gnclk[n1].c_str(), "%d", &b) == 1) varsd_gnclk[n2] = b;
		} else if (sscanf(inp, "txt2ll(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			long long int b;
			if (sscanf(varst_gnclk[n1].c_str(), "%lld", &b) == 1) varsd_gnclk[n2] = b;
		} else if (sscanf(inp, "txt2dbl(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			double b;
			if (sscanf(varst_gnclk[n1].c_str(), "%lf", &b) == 1) varsdbl_gnclk[n2] = b;
		} else if (sscanf(inp, "getntver(%31[A-Za-z]);", name) == 1) {
			if (gnsys) varst_gnclk[name] = get_nt_ver();
		} else if (sscanf(inp, "getsysarch(%31[A-Za-z]);", name) == 1) {
			if (gnsys) varst_gnclk[name] = get_sysarch();
		} else if (sscanf(inp, "getpcname(%31[A-Za-z]);", name) == 1) {
			if (gnsys) varst_gnclk[name] = get_pc_name();
		} else if (sscanf(inp, "getusername(%31[A-Za-z]);", name) == 1) {
			if (gnsys) varst_gnclk[name] = get_user_name();
		} else if (strncmp(inp, "resetcolor();", 13) == 0) {
			if (gnsys) set_console_color(color);
		} else if (sscanf(inp, "logmessage(%31[A-Za-z], %31[A-Za-z]) -> %31[A-Za-z];", n1, n2, name) == 3) {
			if (varst_gnclk.count(n1) && varst_gnclk.count(n2) && gnsys) varst_gnclk[name] = log_message(varst_gnclk[n1].c_str(), varst_gnclk[n2].c_str());
		} else if (sscanf(inp, "findstr(%31[A-Za-z]) -> %31[A-Za-z];", n1, n2) == 2) {
			if (varst_gnclk.count(n1) && gnsys) varst_gnclk[n2] = findstr(varst_gnclk[n1]);
		} else if (sscanf(inp, "nullxor(%31[A-Za-z]);", name) == 1) {
			if (varsd_gnclk.count(name)) asm volatile("xor %0, %0":"=r"(varsd_gnclk[name]));
		} else if (sscanf(inp, "gettsc() -> %31[A-Za-z], %31[A-Za-z];", n1, n2) == 2) {
			asm volatile("rdtsc":"=a"(varsd_gnclk[n1]),"=d"(varsd_gnclk[n2]));
		} else if (sscanf(inp, "gettscllu() -> %31[A-Za-z];", name) == 1) {
			if (!ll) {
				printf("CompareError: use $use ll to continue\n");
				ferr = true;
				return;
			} else {
				unsigned int lo, hi;
				asm volatile("rdtsc":"=a"(lo),"=d"(hi));
				varsllu_gnclk[name] = ((unsigned long long int)hi << 32)|lo;
			}
		} else if (sscanf(inp, "cpuinfo(%u) -> %31[A-Za-z], %31[A-Za-z], %31[A-Za-z], %31[A-Za-z];", &valdu, n1, n2, n3, n4) == 5) {
			asm volatile ("cpuid":"=a"(varsdu_gnclk[n1]),"=b"(varsdu_gnclk[n2]),"=c"(varsdu_gnclk[n3]),"=d"(varsdu_gnclk[n4]):"a"(valdu));
		} else if (sscanf(inp, "uint2txt12l(%31[A-Za-z], %31[A-Za-z], %31[A-Za-z]) -> %31[A-Za-z];", n1, n2, n3, name) == 4) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2) && varsdu_gnclk.count(n3)) {
				unsigned int i1 = varsdu_gnclk[n1];
				unsigned int i2 = varsdu_gnclk[n2];
				unsigned int i3 = varsdu_gnclk[n3];
				char str[13];
				memcpy(str, &i1, 4);
				memcpy(str+4, &i2, 4);
				memcpy(str+8, &i3, 4);
				str[12] = '\0';
				varst_gnclk[name] = std::string(str);
			}
		} else if (sscanf(inp, "uint2txt8l(%31[A-Za-z], %31[A-Za-z]) -> %31[A-Za-z];", n1, n2, name) == 3) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2)) {
				unsigned int i1 = varsdu_gnclk[n1];
				unsigned int i2 = varsdu_gnclk[n2];
				char str[9];
				memcpy(str, &i1, 4);
				memcpy(str+4, &i2, 4);
				str[8] = '\0';
				varst_gnclk[name] = std::string(str);
			}
		} else if (sscanf(inp, "uint2txt16l(%31[A-Za-z], %31[A-Za-z], %31[A-Za-z], %31[A-Za-z]) -> %31[A-Za-z];", n1, n2, n3, n4, name) == 5) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2) && varsdu_gnclk.count(n3) && varsdu_gnclk.count(n4)) {
				unsigned int i1 = varsdu_gnclk[n1];
				unsigned int i2 = varsdu_gnclk[n2];
				unsigned int i3 = varsdu_gnclk[n3];
				unsigned int i4 = varsdu_gnclk[n4];
				char str[17];
				memcpy(str, &i1, 4);
				memcpy(str+4, &i2, 4);
				memcpy(str+8, &i3, 4);
				memcpy(str+12, &i4, 4);
				str[16] = '\0';
				varst_gnclk[name] = std::string(str);
			}
		} else if (sscanf(inp, "uint2txt4l(%31[A-Za-z]) -> %31[A-Za-z];", n1, n2) == 2) {
			if (varsdu_gnclk.count(n1)) {
				unsigned int i1 = varsdu_gnclk[n1];
				char buf[5];
				memcpy(buf, &i1, 4);
				buf[4] = '\0';
				varst_gnclk[std::string(n2)] = std::string(buf);
			}
		} else if (sscanf(inp, "andu(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2)) logic = (varsdu_gnclk[n1] & varsdu_gnclk[n2]) ? 1 : 0;
		} else if (sscanf(inp, "and(%31[A-Za-z], %31[A-Za-z]);", n1, n2) == 2) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) logic = (varsd_gnclk[n1] & varsd_gnclk[n2]) ? 1 : 0;
		} else if (strncmp(inp, "savevar();", 10) == 0) {
			save_variables(vars, "vars.gnc");
		} else if (strncmp(inp, "loadvar();", 10) == 0) {
			load_variables(vars, "vars.gnc");
		} else if (sscanf(inp, "getfrom(%31[A-Za-z0-9]) -> %31[A-Za-z];", n1, n2) == 2) {
			if (vars.count(n1)) varsdbl_gnclk[n2] = vars[n2];
		} else if (sscanf(inp, "setto(%31[A-Za-z]) -> %31[A-Za-z0-9];", n1, n2) == 2) {
			if (varsdbl_gnclk.count(n1)) vars[n2] = varsdbl_gnclk[n1];
		} else if (sscanf(inp, "bcalc(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsd_gnclk.count(n1) && varsd_gnclk.count(n2)) {
				if (op == '^') varsd_gnclk[n3] = varsd_gnclk[n1]^varsd_gnclk[n2];
				else if (op == '>') varsd_gnclk[n3] = varsd_gnclk[n1]>>varsd_gnclk[n2];
				else if (op == '<') varsd_gnclk[n3] = varsd_gnclk[n1]<<varsd_gnclk[n2];
				else if (op == '&') varsd_gnclk[n3] = varsd_gnclk[n1]&varsd_gnclk[n2];
				else if (op == '|') varsd_gnclk[n3] = varsd_gnclk[n1]|varsd_gnclk[n2];
			}
		} else if (sscanf(inp, "bcalcu(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsdu_gnclk.count(n1) && varsdu_gnclk.count(n2)) {
				if (op == '^') varsdu_gnclk[n3] = varsdu_gnclk[n1]^varsdu_gnclk[n2];
				else if (op == '>') varsdu_gnclk[n3] = varsdu_gnclk[n1]>>varsdu_gnclk[n2];
				else if (op == '<') varsdu_gnclk[n3] = varsdu_gnclk[n1]<<varsdu_gnclk[n2];
				else if (op == '&') varsdu_gnclk[n3] = varsdu_gnclk[n1]&varsdu_gnclk[n2];
				else if (op == '|') varsdu_gnclk[n3] = varsdu_gnclk[n1]|varsdu_gnclk[n2];
			}
		} else if (sscanf(inp, "bcalcll(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsll_gnclk.count(n1) && varsll_gnclk.count(n2)) {
				if (op == '^') varsll_gnclk[n3] = varsll_gnclk[n1]^varsll_gnclk[n2];
				else if (op == '>') varsll_gnclk[n3] = varsll_gnclk[n1]>>varsll_gnclk[n2];
				else if (op == '<') varsll_gnclk[n3] = varsll_gnclk[n1]<<varsll_gnclk[n2];
				else if (op == '&') varsll_gnclk[n3] = varsll_gnclk[n1]&varsll_gnclk[n2];
				else if (op == '|') varsll_gnclk[n3] = varsll_gnclk[n1]|varsll_gnclk[n2];
			} else if (!ll) {
				printf("CalcError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "bcalcllu(%31[A-Za-z] %c %31[A-Za-z]) -> %31[A-Za-z];", n1, &op, n2, n3) == 4) {
			if (varsllu_gnclk.count(n1) && varsllu_gnclk.count(n2)) {
				if (op == '^') varsllu_gnclk[n3] = varsllu_gnclk[n1]^varsllu_gnclk[n2];
				else if (op == '>') varsllu_gnclk[n3] = varsllu_gnclk[n1]>>varsllu_gnclk[n2];
				else if (op == '<') varsllu_gnclk[n3] = varsllu_gnclk[n1]<<varsllu_gnclk[n2];
				else if (op == '&') varsllu_gnclk[n3] = varsllu_gnclk[n1]&varsllu_gnclk[n2];
				else if (op == '|') varsllu_gnclk[n3] = varsllu_gnclk[n1]|varsllu_gnclk[n2];
			} else if (!ll) {
				printf("CalcError: use $use ll to continue\n");
				ferr = true;
				return;
			}
		} else if (sscanf(inp, "isdefd(%31[A-Za-z]);", name) == 1) {
			logic = (varsd_gnclk.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "isdeft(%31[A-Za-z]);", name) == 1) {
			logic = (varst_gnclk.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "isdefdbl(%31[A-Za-z]);", name) == 1) {
			logic = (varsdbl_gnclk.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "isdefdu(%31[A-Za-z]);", name) == 1) {
			logic = (varsdu_gnclk.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "isdefll(%31[A-Za-z]);", name) == 1) {
			if (!ll) {
				printf("CompareError: use $use ll to continue.\n");
				ferr = true;
				return;
			} else logic = (varsll_gnclk.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "isdefllu(%31[A-Za-z]);", name) == 1) {
			if (!ll) {
				printf("CompareError: use $use ll to continue.\n");
				ferr = true;
				return;
			} else logic = (varsllu_gnclk.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "isdefvar(%31[A-Za-z]);", name) == 1) {
			logic = (vars.count(name)) ? 1 : 0;
		} else if (sscanf(inp, "%31[A-Za-z].add(%31[A-Za-z]);", n1, n2) == 2) {
			if (varst_gnclk.count(n2)) {
				varst_gnclk[n1] += varst_gnclk[n2];
			}
		}
	}
}

void errorhappened(const char* err) {
	set_console_color(64);
	system("cls");
	printf("%s", err);
	while (true) {}
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
						else if (v == "what") lang = 5;
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
			} else if (strcmp(inp, "what") == 0) {
				changef(setf,"lang=","lang=what");
				lang=5;
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
			printf("\n");
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
			varsll_gnclk.clear();
			varsllu_gnclk.clear();
			varsdbl_gnclk.clear();
			varsdu_gnclk.clear();
			load_file(filename);
			int pc = 0;
			while (pc < total_lines) {
				if (!ferr) {
					char cl[1024];
					strncpy(cl,program[pc],sizeof(cl));
					cl[sizeof(cl)-1] = '\0';
					char* cptr = strstr(cl, " ;-");
					if (cptr) *cptr = '\0';
    				gnclk(cl, pc);
    			}
    			pc++;
    		}
    		if (depth != 0) {
    			printf("Stopped on depth No. %d\n", depth);
			}
			gncsab = false;
			gnsys = false;
			ferr = false;
		} else {
			printf("%s", log_message(findstr("notfound").c_str(), findstr("err").c_str()));
		}
	}
}