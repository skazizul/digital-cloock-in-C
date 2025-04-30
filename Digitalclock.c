#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
int choose;
void clearscreen(); 
int welcomeprint();
void showtime();

int main(){
   
    welcomeprint();
    while(1){
        clearscreen();
        showtime();
        
       
    }
    return 0;
}
void clearscreen(){
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
}
void showtime(){
    time_t rawtime;
    struct tm *timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char buffer[100];
    if(choose == 1){
        strftime(buffer,sizeof(buffer),"%H : %M : %S ",timeinfo);
        printf("Current Time Is : %s\n",buffer);
       
    }else{
        strftime(buffer,sizeof(buffer),"%I : %M : %S %p",timeinfo);
        printf("Current Time Is : %s\n",buffer);
    }
    strftime(buffer,sizeof(buffer),"%A %d/%m/%Y\n",timeinfo);
    printf("Date : %s\n",buffer);
    
    sleep(1);
}
int welcomeprint(){
    printf("Welcome To The Digital Clock !\n");
    printf("Devlope By : SK AZIZUL HOSEN\n");
    printf("1. 24 Hours Format\n");
    printf("2. 12 Hours Format (Default)\n");
    printf("Now, Choose One Option : ");
    scanf("%d",&choose);
}
