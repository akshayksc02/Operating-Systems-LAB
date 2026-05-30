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
    fcfs(req, n, head);

    return 0;
}

