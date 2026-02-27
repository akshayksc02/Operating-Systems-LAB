#include<stdio.h>

void linear_search(int* arr,int key,int size){
    for(int i=0;i<=size;i++){
        if(arr[i]==key){
            printf("%d is present inside the array",key);
            printf("\nAt position %d",i);
            return;
        }
    }
    printf("%d is not present inside the array",key);
}

void binary_search(int* arr,int key,int size){
    int low=0,high=size-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key){
            printf("%d is present inside the array",key);
            printf("\nAt position %d",mid);
            return;
        }
        else if(key < arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    printf("%d is not present inside the array",key);
}
int main(){
    int arr[10],n,key;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    printf("Enter %d elements : \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key : ");
    scanf("%d",&key);

    printf("\nLinear Search:");
    linear_search(arr,key,n);
    printf("\n");

    printf("\nBinary Search:");
    binary_search(arr,key,n);

    return 0;
}
