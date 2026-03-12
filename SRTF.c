#include<stdio.h>

struct Process{
    char name[10];
    int AT,BT,CT,TAT,WT,RT,remaining,start;
}p[10];

void Input(int n){
    for(int i=0;i<n;i++){
        printf("Enter Process name , Arriving Time , Burst Time : ");
        scanf("%s %d %d",&p[i].name,&p[i].AT,&p[i].BT);
        p[i].remaining=p[i].BT;
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
    printf("\nPID \t AT \t BT \t CT \t TAT \t WT \t RT");
    for(int i=0;i<n;i++){
        printf("\n%s \t %d \t %d \t %d \t %d \t %d \t %d",p[i].name,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
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

void SRTF(int n){
    Input(n);
    sort(n);
    int CPUTime=0;
    int completed[10]={0};
    int done=0;

    while(done!=n){
        int idx=-1,min=9999;
        for(int i=0;i<n;i++){
            if(!completed[i] && p[i].AT<=CPUTime){
                if(p[i].remaining < min){
                    min=p[i].remaining;
                    idx=i;
                }
            }
        }

        if(idx==-1){
            CPUTime++;
            continue;
        }

        if(p[idx].remaining == p[idx].BT){
            p[idx].start = CPUTime;
        }

        p[idx].remaining--;
        CPUTime++;
        if(p[idx].remaining == 0){
            p[idx].CT= CPUTime;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            p[idx].RT = p[idx].start - p[idx].AT ;
            done++;
            completed[idx]=1; 
        }
            
    }

    Output(n);
}

int main(){
    int n;
    printf("Enter number of Processes : ");
    scanf("%d",&n);
    SRTF(n);
}