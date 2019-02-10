// vm.c
// Created by Jeremy McCormick on 2/4/19.
// Runs the associated process file given to it by
// scheduler
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
node ** head;//Head and tail for each queue LL
node ** tail;
int size[4];// One for each priority
int counter = 0;;

typedef struct node {
    node * next;
    node * prev;
    proc * prc;
}node;

int main(int argc, char **argv) {
    for(int i = 0; i < 4; i++) {
        head[i] = NULL;
        tail[i] = NULL;
    }
    sched();
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

int run(proc * prc) {
    int c = getNext(prc);
    printRun(prc);
    while(c != 0){
        if(doesIOBlock()) {
            closeProc(prc);
            return -1;
        }
        printf("\nCurrent Exec: %d\n",c);
        clk += c;
        c = getNext(prc);
    }
    closeProc(prc);
    return 0;
}

int sched() {
    loadNew();
    for(int i = 0; i < 4; i++) {
        while(size[i] > 0) {
            proc * next = dequeue(i);
            int ret = run(next);
            if(ret == -1)
                enqueue(next);
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
    node * newnode = malloc(sizeof(node));
    size[proc1->priority]++;
    if(head[proc1->priority] == NULL) {
        head[proc1->priority] = newnode;
        tail[proc1->priority] = newnode;
        newnode->next = NULL;
    }
    else {
        newnode->next = head[proc1->priority];
        head[proc1->priority]->prev = newnode;
        head[proc1->priority] = newnode;
    }

}

proc * dequeue(int priority) {
    if(size[priority] == 0) {
        return NULL;
    }
    else if(size[priority] == 1){
        node * ret = head[priority];
        head[priority] = NULL;
        tail[priority] = NULL;
        size[priority]--;
        return ret->prc;
    }
    else {
        node * ret = tail[priority];
        tail[priority] = ret->prev;
        tail[priority]->next = NULL;
        size[priority]--;
        return ret->prc;
    }
}
