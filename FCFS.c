#include<stdio.h>

struct Process{
    char name[10];
    int AT,BT,CT,TAT,WT,RT;
}p[10];

int CPUTime=0;

void Input(int n){
    for(int i=0;i<n;i++){
        printf("Enter Process name , Arriving Time , Burst Time : ");
        scanf("%s %d %d",&p[i].name,&p[i].AT,&p[i].BT);
    }

}

void ReadyQueue(int size){
    struct Process temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++)
            if(p[j].AT>p[j+1].AT){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
    }
}

void Compute(int n){
    for(int i=0;i<n;i++){
        printf("Executing process : %s \n",p[i].name);
        int startTime=CPUTime;
        printf("Start Time & CPUTime : %d %d\n",startTime,CPUTime);
        CPUTime=CPUTime+p[i].BT;
        p[i].CT=CPUTime;
        p[i].TAT=p[i].CT-p[i].AT;
        p[i].WT=p[i].TAT-p[i].BT;
        p[i].RT=startTime-p[i].AT;
    }
}

void Output(int n){
    printf("\nProcess \t AT \t BT \t CT \t TAT \t WT \t RT");
    for(int i=0;i<n;i++){
        printf("\n%s \t %d \t %d \t %d \t %d \t %d \t %d",p[i].name,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
    }
}
int main(){
    int n;
    printf("Enter number of Processes : ");
    scanf("%d",&n);

    Input(n);
    ReadyQueue(n);
    Compute(n);
    Output(n);
}
