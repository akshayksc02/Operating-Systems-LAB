#include<stdio.h>

struct Process{
    char name[10];
    int AT,BT,CT,TAT,WT,RT;
    int priority;
}p[10];

void Input(int n){
    for(int i=0;i<n;i++){
        printf("Enter Process name , Arriving Time , Burst Time , Priority : ");
        scanf("%s %d %d %d",&p[i].name,&p[i].AT,&p[i].BT,&p[i].priority);
    }
}

void sort(int n){
    struct Process temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)
            if(p[j].AT>p[j+1].AT){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
    }
}

void Output(int n){
    float avgWT=0,avgTAT=0,avgRT=0;
    printf("\nPID \t AT \t BT \t P \t CT \t TAT \t WT \t RT");
    for(int i=0;i<n;i++){
        printf("\n%s \t %d \t %d \t %d \t %d \t %d \t %d \t %d",p[i].name,p[i].AT,p[i].BT,p[i].priority,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
        avgWT+=p[i].WT;
        avgTAT+=p[i].TAT;
        avgRT+=p[i].RT;
    }
    avgWT/=n;
    avgTAT/=n;
    avgRT/=n;
    printf("\nAverage WT : %.3f",avgWT);
    printf("\nAverage TAT : %.3f",avgTAT);
    printf("\nAverage RT : %.3f",avgRT);
}

void PriorityNP(int n){
    Input(n);
    sort(n);
    int done=0,CPUTime=0,completed[10]={0};
    while(done!=n){
        int idx=-1,minP=999;
        for(int i=0;i<n;i++){
            if(!completed[i] && p[i].AT <= CPUTime){
                if(p[i].priority < minP){
                    minP = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx == -1){
            CPUTime++;
            continue;
        }

        int startTime=CPUTime;
        CPUTime=CPUTime+p[idx].BT;
        p[idx].CT=CPUTime;
        p[idx].TAT=p[idx].CT-p[idx].AT;
        p[idx].WT=p[idx].TAT-p[idx].BT;
        p[idx].RT=startTime-p[idx].AT;
        completed[idx]=1;
        done++;

    }

    Output(n);

}

int main(){
    int n;
    printf("Enter number of Processes : ");
    scanf("%d",&n);
    PriorityNP(n);
}