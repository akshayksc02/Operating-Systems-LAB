#include <stdio.h>

int main()
{   
    printf("Akshay KS\n1BM24CS029\n");
    int blocks[100], indexBlock, n, i, block[50], choice;

    // Initialize all blocks as free
    for(i = 0; i < 100; i++)
        blocks[i] = 0;
    do
    {
        printf("Enter index block: ");
        scanf("%d", &indexBlock);
        if(blocks[indexBlock] == 1 || indexBlock >= 100)
        {
            printf("Index block already allocated or invalid.\n");
        }
        else
        {
            printf("Enter number of blocks needed: ");
            scanf("%d", &n);
            printf("Enter the block numbers:\n");
            int can_allocate = 1;
            for(i = 0; i < n; i++)
            {
                scanf("%d", &block[i]);

                if(blocks[block[i]] == 1 || block[i] >= 100)
                {
                    can_allocate = 0;
                }
            }

            if(can_allocate)
            {
                blocks[indexBlock] = 1;

                printf("Allocated blocks are:\n");

                for(i = 0; i < n; i++)
                {
                    blocks[block[i]] = 1;
                    printf("%d ", block[i]);
                }
                printf("\nFile allocated successfully.\n");
            }
            else
            {
                printf("Allocation not possible.\n");
            }
        }
        printf("\nDo you want to allocate another file?\n");
        printf("1. Yes\n0. No\n");

        scanf("%d", &choice);

    } while(choice == 1);

    return 0;
}
