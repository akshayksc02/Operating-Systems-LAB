#include <stdio.h>
#include <string.h>

struct SubDirectory
{
    char subname[30];
    char files[10][30];
    int fileCount;
};

struct MainDirectory
{
    char dname[30];
    struct SubDirectory subdir[10];
    int subCount;
};

void hierarchical()
{
    struct MainDirectory dir[10];

    int mainCount, i, j, k;

    printf("\nEnter number of main directories: ");
    scanf("%d", &mainCount);

    for(i = 0; i < mainCount; i++)
    {
        printf("\nEnter main directory name: ");
        scanf("%s", dir[i].dname);

        printf("Enter number of subdirectories: ");
        scanf("%d", &dir[i].subCount);

        for(j = 0; j < dir[i].subCount; j++)
        {
            printf("\nEnter subdirectory name: ");
            scanf("%s", dir[i].subdir[j].subname);

            printf("Enter number of files: ");
            scanf("%d", &dir[i].subdir[j].fileCount);

            for(k = 0; k < dir[i].subdir[j].fileCount; k++)
            {
                printf("Enter file %d name: ", k + 1);
                scanf("%s", dir[i].subdir[j].files[k]);
            }
        }
    }

    printf("\nHierarchical Directory Structure\n");
    printf("ROOT\n");

    for(i = 0; i < mainCount; i++)
    {
        printf(" |-- %s\n", dir[i].dname);

        for(j = 0; j < dir[i].subCount; j++)
        {
            printf("      |-- %s\n", dir[i].subdir[j].subname);

            for(k = 0; k < dir[i].subdir[j].fileCount; k++)
            {
                printf("            |-- %s\n",
                       dir[i].subdir[j].files[k]);
            }
        }
    }
}

int main()
{
    printf("Akshay KS\n1BM24CS029\n");
    hierarchical();
    return 0;
}