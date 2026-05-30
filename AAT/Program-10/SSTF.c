#include <stdio.h>
#include <stdlib.h>



void sstf(int req[], int n, int head) {
    int visited[100] = {0};
    int count = 0, totalSeek = 0;

    printf("\nSSTF Seek Sequence: %d ", head);

    while(count < n) {

        int min = 99999;
        int index = -1;

        for(int i = 0; i < n; i++) {

            if(!visited[i]) {

                int distance = abs(head - req[i]);

                if(distance < min) {
                    min = distance;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        totalSeek += min;
        head = req[index];

        printf("%d ", head);

        count++;
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
}

int main() {

    int req[100], n, head, choice, diskSize;
    printf("Akshay KS\n1BM24CS029\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);
    sstf(req, n, head);

    return 0;
}