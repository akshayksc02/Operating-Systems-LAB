#include<stdio.h>

void duplicate(int* arr,int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                printf("Duplicate number %d is present",arr[i]);
                return;
            }
        }
    }
    printf("No duplicates are present");
}

int main(){
    int arr[10],n,min;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter %d elements : \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    duplicate(arr,n);
    return 0;
}

