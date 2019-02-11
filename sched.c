// sched.c
// Created by Jeremy McCormick on 2/4/19.
// Schedules and loads new processes generated by procgen. sched() loads the new 
// files and picks which one to run. run() then runs it with random I/O blocks.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "proc.h"
#include "sched.h"
//Functions
void clearScreen();
int doesIOBlock();
int run(proc * prc);
void loadNew();
void enqueue(proc * proc1);
proc * dequeue(int priority);
int sched();

//Globals
FILE * fp;
int clk;
proc * queue[4][10001];
int head[4];//Head and tail for each queue
int tail[4];
int size[4];// One for each priority
int counter = 0;;


int main(int argc, char **argv) {
    for(int i = 0; i < 4; i++) {
        head[i] = 10000;
        tail[i] = 10000;
        size[i] = 0;
    }
    sched();
    while(size[0] > 0 || size[1] > 0 || size[2] > 0 || size[3] > 0) {
        sched();
    }
}

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    fprintf(stdout, CLEAR_SCREEN_ANSI, 12);
}
void printRun(proc * proc1) {
    printf("Now Running file num : %d\n", getNumber(proc1));
    printf("Location: %i\n",getWhereAt(proc1));
    printf("Priority: %i\n",getPriority(proc1));
    printf("ExecTime: %i\n",getTime(proc1));
    printf("Memory: %i\n", getMemory(proc1));

}

int doesIOBlock() {
    int r = (rand() % 100);
    if(r < 2)
        return 1;
    return 0;

}

int run(proc * prc) {
    printRun(prc);
    int c = getNext(prc);
    while(c != 0){
        if(doesIOBlock() == 1) {
            return -1;
        }
        clk += c;
        c = getNext(prc);
        printf("Next Exec : %i\n", c);
    }
    closeProc(prc);
    return 0;
}

int sched() {
    loadNew();
     for(int i = 0; i < 4; i++) {
          proc * prev; 
           //Gets current size, to avoid enqueue continually running same thing.
          for(int currentsize = size[i];  currentsize > 0 ; currentsize--) {
                proc * next = dequeue(i);
                prev = next;
                int ret = run(next);
                if(ret == -1)
                    enqueue(next);
                //else
                  // closeProc(next);
            }  
        }   
    return 0;
}

void loadNew() {
    //Check for new files
    char buf[100];
    //Open with counter filename
    snprintf(buf, sizeof(buf), "%i.proc", counter);
    
    while(access(buf, F_OK) != -1) {
        proc * newproc = openProc(counter);
        enqueue(newproc);
        counter++;
        //Open with counter filename
        snprintf(buf, sizeof(buf), "%i.proc", counter);
    }
}

void enqueue(proc * proc1) {
    int prior = proc1->priority;
    queue[prior][head[prior]] = proc1;
    head[prior]--;
    size[prior]++;

}

proc * dequeue(int priority) {
    if(size[priority] == 0) {
        return NULL;
    }
    proc * ret = queue[priority][tail[priority]];
    tail[priority]--;
    size[priority]--;
    return ret;
}
