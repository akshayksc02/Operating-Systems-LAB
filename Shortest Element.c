#include<stdio.h>

void smallest(int* arr,int size){
    int min=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]<=min){
            min=arr[i];
        }
    }
    printf("The min element in the array is : %d",min);
}

int main(){
    int arr[10],n,min;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter %d elements : \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    smallest(arr,n);
    return 0;
}
