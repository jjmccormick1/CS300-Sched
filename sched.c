// vm.c
// Created by Jeremy McCormick on 2/4/19.
// Runs the associated process file given to it by
// scheduler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "proc.h"

//Functions
void clearScreen();
int doesIOBlock();
int run(int num);

//Globals
int location, priority, exectime, memory;
FILE * fp;
int clk;


int main(int argc, char **argv) {
    //srand(time(NULL));
    if(argc != 2) {
        printf("Wrong args!");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    clearScreen();
    run(0);
}

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    fprintf(stdout, CLEAR_SCREEN_ANSI, 12);
}
void printRun(proc * proc1) {
    printf("Now Running file num : %d\n", proc1->num);
    printf("Location: %i\n",proc1->whereAt);
    printf("Priority: %i\n",proc1->priority);
    printf("ExecTime: %i\n",proc1->execTime);
    printf("Memory: %i\n", proc1->memory);

}

int doesIOBlock() {
    int r = (rand() % 100);
    if(r < 2)
        return 1;
    return 0;

}

int run(int num) {
    proc * proc1 = openProc(num);
    int c = getNext(proc1);
    printRun(proc1);
    while(c != 0){
        if(doesIOBlock()) {
            closeProc(proc1);
            return -1;
        }
        printf("\nCurrent Exec: %d\n",c);
        clk += c;
        c = getNext(proc1);
    }
    closeProc(proc1);
    return 0;
}

int sched() {
    
}




