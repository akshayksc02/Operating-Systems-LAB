#include <stdio.h>
#include <stdlib.h>

void scan(int req[], int n, int head, int diskSize) {

    int temp[100];
    int totalSeek = 0;

    // Copy requests
    for(int i = 0; i < n; i++)
        temp[i] = req[i];

    // Sort requests
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {

            if(temp[j] > temp[j + 1]) {

                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    int index;

    // Find first request greater than head
    for(int i = 0; i < n; i++) {

        if(temp[i] >= head) {
            index = i;
            break;
        }
    }

    printf("\nSCAN Seek Sequence: %d ", head);

    // Move right
    for(int i = index; i < n; i++) {

        totalSeek += abs(head - temp[i]);
        head = temp[i];

        printf("%d ", head);
    }

    // Move till disk end
    totalSeek += abs(head - (diskSize - 1));
    head = diskSize - 1;

    // Move left
    for(int i = index - 1; i >= 0; i--) {

        totalSeek += abs(head - temp[i]);
        head = temp[i];

        printf("%d ", head);
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
    
    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    scan(req, n, head, diskSize);

    return 0;
}