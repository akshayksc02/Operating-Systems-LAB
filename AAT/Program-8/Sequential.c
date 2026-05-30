#include <stdio.h>
#include <string.h>

void main() {
    printf("Akshay KS\n1BM24CS029\n");
    int blocks[100], start, length, i, choice;

    for(i = 0; i < 100; i++)
        blocks[i] = 0;

    do {
        printf("Enter the starting block and length of the file: ");
        scanf("%d %d", &start, &length);

        int can_allocate = 1;

        // Check if blocks are within range and free
        for(i = start; i < (start + length); i++) {
            if(blocks[i] == 1 || i >= 100) {
                can_allocate = 0;
                break;
            }
        }

        if(can_allocate) {
            for(i = start; i < (start + length); i++) {
                blocks[i] = 1;
                printf("Block %d allocated\n", i);
            }
            printf("File allocated successfully.\n");
        } else {
            printf("Error: Blocks already allocated or out of range.\n");
        }

        printf("Do you want to enter another file? (1-Yes / 0-No): ");
        scanf("%d", &choice);
    } while(choice == 1);
}
