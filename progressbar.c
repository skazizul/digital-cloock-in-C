#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
const int progress_bar_length = 50;
const int max_task=5;
typedef struct{
    int id;
    int progress;
    int step;
} Task;
void printbar(Task task);
void clearscreen();
int main(){
    Task tasks[max_task];
    srand(time(NULL));
    for(int i = 0; i < max_task; i++){
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 10 +1;
    }
    int task_incomplete = 1;
    while(task_incomplete){
        task_incomplete = 0;
        clearscreen();
        for(int i = 0; i < max_task; i++){
            tasks[i].progress += tasks[i].step;
            if(tasks[i].progress > 100){
                tasks[i].progress = 100;
            }else if(tasks[i].progress < 100){
                task_incomplete = 1;
            }
           printbar(tasks[i]); 
        }
        sleep(1);
    }
    printf("All Tasks Completed ! \n");

    return 0;
}
void printbar(Task task){
    int barshow = (task.progress*progress_bar_length)/100;
    printf("Task %d : [",task.id);
    for(int i = 0; i < progress_bar_length; i++){
        if(i < barshow){
            printf("=");
        }else{
            printf(" ");
        }
    }
    printf("] %d%%\n",task.progress);
}
void clearscreen(){
    #ifdef _WIN32
      system("cls");
    #else
      system("clear");
    #endif
}