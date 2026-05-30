#include <stdio.h>
#include<stdlib.h>

void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int req[20], n;
    int head;
    int i, totalSeek = 0;
    printf("Akshay KS\n1BM24CS029\n");
    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d", &head);
    sort(req, n);
    int index;
    for (i = 0; i < n; i++)
    {
        if (head < req[i])
        {
            index = i;
            break;
        }
    }
    printf("\nSeek Sequence: ");
    for (i = index; i < n; i++)
    {
        printf("%d ", req[i]);
        totalSeek += abs(head - req[i]);
        head = req[i];
    }
    for (i = 0; i < index; i++)
    {
        printf("%d ", req[i]);
        totalSeek += abs(head - req[i]);
        head = req[i];
    }
    printf("\n\nTotal Seek Time = %d\n", totalSeek);
    return 0;
}