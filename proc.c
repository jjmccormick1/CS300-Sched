//
// Created by jj on 2/6/19.
//

#include <stdlib.h>
#include "proc.h"

struct proc {
int whereAt;
int priority;
int execTime;
int memory;
int openCount;
FILE * fp;
};

proc * openProc(int num) {
    proc * proc1 = malloc(sizeof(proc));
    proc1->openCount = 0;
    char buf[100];
    //Open with counter filename
    snprintf(buf, sizeof(buf), "%i.proc", num);
    proc1->fp = fopen(buf,"r");
    fscanf(proc1->fp,"%d\n%d\n%d\n%d\n",&proc1->whereAt, &proc1->priority, &proc1->execTime, &proc1->memory);
    if(proc1->whereAt > 0)
        fseek(proc1->fp, proc1->whereAt * 3, SEEK_CUR); // Goto where at, may be zero
    return proc1;
}

int closeProc(proc * proc1) {
    proc1->whereAt = proc1->whereAt + proc1->openCount;
    fclose(proc1->fp);
    return 1;
}
int getPriority(proc * proc1) {
    return proc1->priority;
}
int getWhereAt(proc * proc1) {
    return proc1->whereAt;
}
int getTime(proc * proc1) {
    return proc1->execTime;
}
void setTime(proc * proc1, int time) {
    proc1->execTime = time;
}
int getMemory(proc * proc1) {
    return proc1->memory;
}
int getNext(proc * proc1) {
    //Current at fp will be after info lines already after reading them
    int next;
    fscanf(proc1->fp, "%d", &next);
    proc1->openCount++;
    return next;
}