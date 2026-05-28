#include<stdio.h>

struct Process{
    char name[10];
    int AT,BT,CT,TAT,WT,RT;
    int start,remaining;
}p[10];

int queue[20];
int front=0,rear=-1;

void enqueue(int i){
    rear++;
    queue[rear]=i;
}

int dequeue(){
    if(front>rear)
        return -1;

    int i=queue[front];
    front++;
    return i;
}

void Input(int n){
    for(int i=0;i<n;i++){
        printf("Enter Process name, Arrival Time, Burst Time: ");
        scanf("%s %d %d",p[i].name,&p[i].AT,&p[i].BT);

        p[i].remaining=p[i].BT;
    }
}

void sort(int n){
    struct Process temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].AT > p[j+1].AT){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

void Output(int n){
    float avgWT=0,avgTAT=0,avgRT=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT");

    for(int i=0;i<n;i++){
        printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d",
        p[i].name,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);

        avgWT+=p[i].WT;
        avgTAT+=p[i].TAT;
        avgRT+=p[i].RT;
    }

    printf("\nAverage WT : %.3f",avgWT/n);
    printf("\nAverage TAT : %.3f",avgTAT/n);
    printf("\nAverage RT : %.3f",avgRT/n);
}

void RoundRobin(int n,int timeQuant){

    int CPUTime=0,completed=0;
    int visited[10]={0};

    Input(n);
    sort(n);

    while(completed < n){

        for(int i=0;i<n;i++){
            if(p[i].AT <= CPUTime && visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }

        int idx = dequeue();

        if(idx == -1){
            CPUTime++;
            continue;
        }

        if(p[idx].remaining == p[idx].BT)
            p[idx].start = CPUTime;

        int execTime = timeQuant;

        if(p[idx].remaining < execTime)
            execTime = p[idx].remaining;

        CPUTime += execTime;
        p[idx].remaining -= execTime;

        for(int i=0;i<n;i++){
            if(p[i].AT <= CPUTime && visited[i]==0){
                enqueue(i);
                visited[i]=1;
            }
        }

        if(p[idx].remaining > 0){
            enqueue(idx);
        }
        else{
            p[idx].CT = CPUTime;
            p[idx].TAT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TAT - p[idx].BT;
            p[idx].RT = p[idx].start - p[idx].AT;

            completed++;
        }
    }

    Output(n);
}

int main(){

    int n,timeQuant;
    printf("Akshay KS\n1BM24CS029\n");

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Time Quantum: ");
    scanf("%d",&timeQuant);

    RoundRobin(n,timeQuant);

    return 0;
}