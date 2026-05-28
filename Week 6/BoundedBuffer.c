#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

// Semaphores
int mutex = 1;
int full = 0;
int empty = SIZE;

// WAIT operation
void wait(int *s) {
    (*s)--;
}

// SIGNAL operation
void signal(int *s) {
    (*s)++;
}

void produce(int item) {
    printf("\nTrying to PRODUCE %d...\n", item);

    if (empty == 0) {
        printf("Buffer FULL → Producer is BLOCKED!\n");
        return;
    }

    wait(&empty);
    wait(&mutex);

    // Critical section
    buffer[in] = item;
    printf("Produced %d at position %d\n", item, in);
    in = (in + 1) % SIZE;

    signal(&mutex);
    signal(&full);
}

void consume() {
    printf("\nTrying to CONSUME...\n");

    if (full == 0) {
        printf("Buffer EMPTY → Consumer is BLOCKED!\n");
        return;
    }

    wait(&full);
    wait(&mutex);

    // Critical section
    int item = buffer[out];
    printf("Consumed %d from position %d\n", item, out);
    out = (out + 1) % SIZE;

    signal(&mutex);
    signal(&empty);
}

void display() {
    printf("\nBuffer state: ");
    if (full == 0) {
        printf("EMPTY\n");
        return;
    }

    int i = out;
    for (int c = 0; c < full; c++) {
        printf("%d ", buffer[i]);
        i = (i + 1) % SIZE;
    }
    printf("\n");

    printf("Semaphores → mutex: %d, full: %d, empty: %d\n", mutex, full, empty);
}

int main() {
    int choice, item;

    while (1) {
        printf("\n--- Bounded Buffer (Semaphore Simulation) ---\n");
        printf("1. Produce\n");
        printf("2. Consume\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                produce(item);
                break;

            case 2:
                consume();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}