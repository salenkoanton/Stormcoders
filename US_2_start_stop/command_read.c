#include<stdio.h>
#include<conio.h>

enum commands{start = 1, stop};

int command_read(void){
    char a = 0;
    while(a != 27){
        a = getch();
        if(a == 72){
            return start;
        }
        if (a == 80){
            return stop;
        }
    }
}
