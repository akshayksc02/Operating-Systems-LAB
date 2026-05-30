#include <stdio.h>
#include <string.h>

struct Directory
{
    char dname[30];
    char files[10][30];
    int fileCount;
};

void twoLevel()
{
    struct Directory dir[10];
    int dirCount, i, j;

    printf("\nEnter number of directories: ");
    scanf("%d", &dirCount);

    for(i = 0; i < dirCount; i++)
    {
        printf("\nEnter directory name: ");
        scanf("%s", dir[i].dname);

        printf("Enter number of files: ");
        scanf("%d", &dir[i].fileCount);

        for(j = 0; j < dir[i].fileCount; j++)
        {
            printf("Enter file %d name: ", j + 1);
            scanf("%s", dir[i].files[j]);
        }
    }

    printf("\nTwo Level Directory Structure\n");
    printf("ROOT\n");

    for(i = 0; i < dirCount; i++)
    {
        printf(" |-- %s\n", dir[i].dname);

        for(j = 0; j < dir[i].fileCount; j++)
        {
            printf("      |-- %s\n", dir[i].files[j]);
        }
    }
}

int main()
{
    printf("Akshay KS\n1BM24CS029\n");
    twoLevel();
    return 0;
}