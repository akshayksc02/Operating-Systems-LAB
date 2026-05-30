#include <stdio.h>

int main()
{
    printf("Akshay KS\n1BM24CS029\n");
    int blocks[100], n, i, fileBlock[50], choice;

    // Initialize all blocks as free
    for(i = 0; i < 100; i++)
        blocks[i] = 0;

    do
    {
        printf("\nEnter number of blocks needed: ");
        scanf("%d", &n);

        printf("Enter the block numbers:\n");

        int can_allocate = 1;

        for(i = 0; i < n; i++)
        {
            scanf("%d", &fileBlock[i]);

            if(blocks[fileBlock[i]] == 1 || fileBlock[i] >= 100)
            {
                can_allocate = 0;
            }
        }

        if(can_allocate)
        {
            printf("Linked Allocation:\n");

            for(i = 0; i < n; i++)
            {
                blocks[fileBlock[i]] = 1;

                if(i != n - 1)
                    printf("%d -> ", fileBlock[i]);
                else
                    printf("%d -> NULL", fileBlock[i]);
            }

            printf("\nFile allocated successfully.\n");
        }
        else
        {
            printf("Allocation not possible.\n");
        }

        printf("\nDo you want to allocate another file?\n");
        printf("1. Yes\n0. No\n");

        scanf("%d", &choice);

    } while(choice == 1);
    return 0;
}
