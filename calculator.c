#include<stdio.h>
#include<math.h>
int main(){
    int choice;
    float first,second,result;
    do{
        printf("\n________________________________________\n");
        printf("     Welcome To The Simple Calculator\n");
        printf("Choose One From That Menu\n");
        printf("1. Addition\n");
        printf("2. Substraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Power\n");
        printf("7. Exit\n");
        printf("Now Enter Your Choice : ");
        scanf("%d",&choice);
        if(choice < 1 || choice > 7){
            printf("Invalid Choice ! ");
            continue;
        }
        if(choice == 7){
            printf("Thank You For Using Simple Calculator \n");
            printf("Develope By : SK AZIZUL HOSEN\n");
            break;
        }
        printf("Enter Your First Number : ");
        scanf("%f",&first);
        printf("Enter Your Second Number : ");
        scanf("%f",&second);
        switch(choice){
            case 1:
            result=first + second;
            break;
            case 2:
            result=first - second;
            break;
            case 3:
            result=first * second;
            break;
            case 4:
            if(second != 0){
                result=first / second;
            } else{
                printf(" Invalid Argument ! ");
                continue;
            }
            break;
            case 5:
            if(second != 0){
                result=(int)first % (int)second;
            }else{
                printf("Invalid Argument !");
                continue;
            }
            break;
            case 6:
            result=pow(first,second);
            break;

        }
        printf(" The Result Is %.2f",result);
    }while(choice != 7);
    return 0;
}