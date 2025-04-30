#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int randomint(int end){
    return rand()%end;
}
int main(){
    srand(time(NULL));
    char gameitem[3]={'s','p','c'};
    int myscore=0;
    int computerscore=0;

    for(int i=0; i<5; i++){
        int randno=randomint(3);
        char minp=' ';
        
        char cinp=gameitem[randno];
        printf(" \nEnter Your Choice (s,p,c) : ");
        scanf(" %c",&minp);
        if(minp!='s' && minp!='p' && minp!='c'){
            printf("invalid choice \n Try Again ");
            i--;
            continue ;
        }
        if((minp=='s' && cinp=='c') ||(minp=='c' && cinp=='p') || (minp=='p' && cinp=='s') ){
             printf("Awesome\n");
                myscore++;
        }else if(minp==cinp){
                printf("DRAW !\n");
        }else{
                printf("Ooo ! \n");
                computerscore++;
            }
        
       
    }

    if(myscore>computerscore){
        printf("I WON ❤️\n");
    }else{
        printf("COMPUTER WON 🤦‍♂️\n");
    }
    printf("my score : %d\ncomputer score : %d",myscore,computerscore);
    return 0;
}