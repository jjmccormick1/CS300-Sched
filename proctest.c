//
// Created by jj on 2/6/19.
//

#include "proc.h"
 int main(void) {
    proc * proc1 = openProc(0);
    printf("At Line: %i\n",getWhereAt(proc1));
    printf("Memory: %i\n",getMemory(proc1));
    printf("Exec Time: %i\n",getTime(proc1));
    printf("Priority: %i\n",getPriority(proc1));
    printf("next: %i\n",getNext(proc1));
    printf("next: %i\n",getNext(proc1));
    printf("next: %i\n",getNext(proc1));
    printf("next: %i\n",getNext(proc1));
}