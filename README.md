# gnconsole
Gimpnotepad's console is a program by gimpnotepad from scratch. 
# Requirements
[gndll.dll](https://github.com/gimpnotepad/gndll/releases/download/release-dll/gndll.dll),

chcp 65001 on cmd

and font Lucida Console or Consolas for Windows 7, not Raster fonts!

<img width="386" height="474" alt="Settings for gnconsole (for CLI-programms)" src="https://github.com/user-attachments/assets/51a3a480-aa24-4ad5-b620-abf87460aadb" />

i mean this by the way

# Examples for gnclk
## Calculator:
```gnclk
txt p = "+";
txt m = "-";
txt mu = "*";
txt d = "/";
txt n = "n";
txt f = "n";
func calcu
cmpt(f,p);
ifl
calc(cf + cs) -> cf;
printd(cf);
stp
ifnl
cmpt(f,m);
ifl
calc(cf - cs) -> cf;
printd(cf);
stp
ifnl
cmpt(f,mu);
ifl
calc(cf * cs) -> cf;
printd(cf);
stp
ifnl
cmpt(f,d);
ifl
calc(cf / cs) -> cf;
printd(cf);
stp
ifnl
cmpt(f,n);
ifl
stp
ifnl
print("error");
stp
stp
stp
stp
endfunc
print("calc:");
int cf = 0;
int cs = 0;
inputd(cf);
inputd(cs);
print("func:");
inputt(f);
callfunc(calcu);
```

## Counter from 0 to 10:
```
int x = 0;
int add = 1;
int f = 10;
cmpd(x,f);
ifl
jmp(11);
stp
printd(x);
calc(x + add) -> x;
jmp(4);
printd(x);
```
