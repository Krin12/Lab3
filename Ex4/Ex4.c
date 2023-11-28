#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#define BUFSIZE 512

char practice_1[BUFSIZE] = "Hello world!";
char practice_2[BUFSIZE] = "This is Ex4 test script";
char practice_3[BUFSIZE] = "This program check your typing time";

int main(){
    time_t start_time, end_time;
    char a[20];
    char buffer[BUFSIZE];
    char buf1[BUFSIZE];
    char buf2[BUFSIZE];
    char buf3[BUFSIZE];
    int wrong_count=0;
    int n;
    int filedes;
    int fd;
    int sum = 0;
    double total = 0;

    printf("Typing test program. Start(Enter)\n");
    printf("<<<<<<<<<<<Press Enter>>>>>>>>>>>>");
    gets(a);
    start_time = time(NULL);

    fprintf(stderr, "%s\n", practice_1);
    gets(buf1);

    fprintf(stderr,"%s\n", practice_2);
    gets(buf2);

    fprintf(stderr, "%s\n", practice_3);
    gets(buf3);
    end_time = time(NULL);


    total = difftime(end_time, start_time);

    sum = strlen(buf1) + strlen(buf2) + strlen(buf3);
    sum /= total/60; 

    for(int i = 0; i < strlen(practice_1); i++) if(buf1[i] != practice_1[i]) wrong_count++;
    for(int i = 0; i < strlen(practice_2); i++) if(buf2[i] != practice_2[i]) wrong_count++;
    for(int i = 0; i < strlen(practice_3); i++) if(buf3[i] != practice_3[i]) wrong_count++;
    

    printf("Error: %d\n",wrong_count); 
    printf("Typing / min: %ld\n", sum);
    printf("Total time: %f\n", total);

    exit(0);

    return 0;
}
