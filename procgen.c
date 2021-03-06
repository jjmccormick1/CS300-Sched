#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

int counter = 0;

int new_process() {
    char buf[100];
    //Open with counter filename
    snprintf(buf, sizeof(buf), "%i.proc", counter);
    FILE * fp = fopen(buf,"w");
    assert(fp != NULL);
    fprintf(fp, "000000000\n"); //Where at in run
    fprintf(fp, "%09d\n", rand() % 4); //Priority 0-3
    fprintf(fp, "%09d\n", (rand() % 46001) + 400); //Exec time 400-40,000
    fprintf(fp, "%09d\n", (rand() % 191) + 10); //Memory 10mb to 200mb
    long num = (rand() % 99001) + 1000;
    //fprintf(fp, "0"); //Where at in run
    for(long i = 0; i < 400; i++) {
        fprintf(fp,"%02d\n",(rand() % 20) + 1);
    }
    fclose(fp);
    counter++;
    return (int)num;
}

int main() {
    int i =0 ;
    while(100 > i) {
        //long ran = (rand() % 9981) + 20;
        new_process();
        //usleep(ran * 1000); // Wait for 20 to 10000 seconds
        i++;
    }

}

