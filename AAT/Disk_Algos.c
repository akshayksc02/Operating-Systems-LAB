#include <stdio.h>
#include <stdlib.h>

void fcfs(int req[], int n, int head) {
    int totalSeek = 0;

    printf("\nFCFS Seek Sequence: %d ", head);

    for(int i = 0; i < n; i++) {
        totalSeek += abs(head - req[i]);
        head = req[i];
        printf("%d ", head);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
}

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

void clook(int req[], int n, int head) {

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

    printf("\nC-LOOK Seek Sequence: %d ", head);

    // Move right
    for(int i = index; i < n; i++) {

        totalSeek += abs(head - temp[i]);
        head = temp[i];

        printf("%d ", head);
    }

    // Jump to beginning
    totalSeek += abs(head - temp[0]);
    head = temp[0];

    printf("%d ", head);

    // Continue moving right
    for(int i = 1; i < index; i++) {

        totalSeek += abs(head - temp[i]);
        head = temp[i];

        printf("%d ", head);
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);
}

int main() {

    int req[100], n, head, choice, diskSize;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\n1. FCFS");
    printf("\n2. SSTF");
    printf("\n3. SCAN");
    printf("\n4. C-LOOK");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            fcfs(req, n, head);
            break;

        case 2:
            sstf(req, n, head);
            break;

        case 3:
            printf("Enter disk size: ");
            scanf("%d", &diskSize);

            scan(req, n, head, diskSize);
            break;

        case 4:
            clook(req, n, head);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}