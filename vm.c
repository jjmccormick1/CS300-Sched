// vm.c
// Created by Jeremy McCormick on 2/4/19.
// Runs the associated process file given to it by
// scheduler
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int location, priority, exectime, memory;
FILE * fp;

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    fprintf(stdout, CLEAR_SCREEN_ANSI, 12);
}
void printRun(char* num) {
    printf("Now Running file num : %s\n", num);
    printf("Location: %i\n",location);
    printf("Priority: %i\n",priority);
    printf("ExecTime: %i\n",exectime);
    printf("Memory: %i\n", memory);

}

int block() {

}

int run() {
    //Go to last location
    fseek(fp, location * 2, SEEK_CUR);
    int blockRand = rand() % 100; //Get 0-99 for 2% test
    if (blockRand < 2)
        block();
}

int main(int argc, char **argv) {
    //srand(time(NULL));
    if(argc != 2) {
        printf("Wrong args!");
        exit(1);
    }
    fp = fopen(argv[1], "r");
    fscanf(fp,"%d\n%d\n%d\n%d",&location, &priority, &exectime, &memory);
    clearScreen();
    printRun(argv[1]);

}

