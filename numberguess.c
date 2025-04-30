#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int guess,random;
    int no_of_attempts=0;
    srand(time(NULL));
    printf("Welcome To The Number Guessing Game ! \n");
    random=rand()%100+1;
    
    do{
        printf("Enter a number between (1 to 100) : ");
        scanf("%d",&guess);
        no_of_attempts++;
      if(guess<random){
        printf("Guess a Larger Number !\n");
      }else if(guess>random){
        printf("Guess a Smaller Number !\n");
      }else{
        printf(" You Have Won The Match %d attempts !\n",no_of_attempts);
      }
    }while(guess!=random);
    printf("Thenk You For Playing This Game ! \n Directed By :-  SK AZIZUL HOSEN");
    return 0;
}