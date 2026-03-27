#include<stdio.h>
#include<math.h>

struct Task{
    char name[10];
    int capacity,time,deadline;
    int remaining,nextArrival;
}t[10];


int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int lcm(int a,int b){
    int result=(a*b)/gcd(a,b);
    return result;
}

void sort(int n){
    struct Task temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(t[j].time>t[j+1].time){
                temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }
}

void check(int n,float util,int hyperperiod){
    float bound=n*(pow(2,(float)1/n)-1);
    if( util<= bound){
        printf("\n%.4f <= %.4f => true",util,bound);
        printf("\nScheduling will occur for %dms",hyperperiod);
    }else if(util <= 1){
        printf("\nScheduling will occur as util obeys %.4f <= 1 => true and will occur for %dms",util,hyperperiod);
    }else{
        printf("\nNot schedulable");
    }
}

int main(){
    int n,completed=0,time=0,hyperperiod=1;
    float util=0;
    printf("Enter number of processes : ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter task name, capacity,time period,deadline: ");
        scanf("%s %d %d %d",&t[i].name,&t[i].capacity,&t[i].time,&t[i].deadline);

        hyperperiod=lcm(hyperperiod,t[i].time);
        util+= (float)t[i].capacity/t[i].time;
        t[i].remaining=0;
        t[i].nextArrival=0;
    }

    sort(n);
    printf("\nLCM : %d",hyperperiod);
    printf("\nEarliest Deadline First Scheduling:");
    printf("\nPID\tCapacity\tTime\tDeadline");
    for(int i=0;i<n;i++){
        printf("\n%s \t %d \t %d \t %d",t[i].name,t[i].capacity,t[i].time,t[i].deadline);
    }

    check(n,util,hyperperiod);

    while(time<hyperperiod){
        int idx=-1,min_dead=9999;
        for(int i=0;i<n;i++){
            if(time==t[i].nextArrival){
                t[i].remaining=t[i].capacity;
                t[i].nextArrival+=t[i].time;
            }
        }

        for(int i=0;i<n;i++){
            if(t[i].remaining > 0){
                int abs_deadline = t[i].nextArrival - t[i].time + t[i].deadline;
                if(abs_deadline < min_dead){
                    min_dead = abs_deadline;
                    idx = i;
                }
            }
        }

        if(idx!=-1){
            printf("\n%dms onwards : Process %s running ",time,t[idx].name);
            time++;
            t[idx].remaining--;
            if(t[idx].remaining==0) completed++;
        }else{
            printf("\n%dms onwards : CPU IdleTime ",time);
            time++;
        }
    }

    return 0;
}
