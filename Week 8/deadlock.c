#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main() {
    int n, m;

    // n = number of processes
    // m = number of resource types
    printf("Akshay KS\n1BM24CS029\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int request[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];

    // Input Allocation matrix
    printf("\nEnter Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Request matrix
    printf("\nEnter Request Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available array
    printf("\nEnter Available Resources:\n");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    bool finish[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    int safeSequence[MAX_PROCESSES];

    // Initialize work = available
    for (int j = 0; j < m; j++) {
        work[j] = available[j];
    }

    // Initialize finish[]
    // If allocation is zero, process already finished
    for (int i = 0; i < n; i++) {
        bool zeroAllocation = true;

        for (int j = 0; j < m; j++) {
            if (allocation[i][j] != 0) {
                zeroAllocation = false;
                break;
            }
        }

        finish[i] = zeroAllocation;
    }

    int count = 0;

    while (1) {
        bool found = false;

        for (int i = 0; i < n; i++) {

            if (finish[i] == false) {

                bool canExecute = true;

                // Check if Request <= Work
                for (int j = 0; j < m; j++) {
                    if (request[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {

                    // Process finishes and releases resources
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = true;
                    safeSequence[count] = i;
                    count++;

                    found = true;
                }
            }
        }

        // No more processes can proceed
        if (!found) {
            break;
        }
    }

    // Check deadlock
    bool deadlock = false;

    for (int i = 0; i < n; i++) {
        if (finish[i] == false) {
            deadlock = true;
            break;
        }
    }

    if (!deadlock) {
        printf("\nNo Deadlock detected.\n");

        printf("Safe Sequence: ");
        for (int i = 0; i < count; i++) {
            printf("P%d", safeSequence[i]);

            if (i != count - 1) {
                printf(" -> ");
            }
        }

        printf("\n");
    }
    else {
        printf("\nDeadlock detected.\n");

        printf("Processes involved in deadlock: ");

        for (int i = 0; i < n; i++) {
            if (finish[i] == false) {
                printf("P%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}