#include <stdio.h>
#include <string.h>

// ---------- Single Level ----------

struct SingleFile
{
    char fname[30];
};

// ---------- Two Level ----------

struct Directory
{
    char dname[30];
    char files[10][30];
    int fileCount;
};

// ---------- Hierarchical ----------

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

// ---------- Single Level Function ----------

void singleLevel()
{
    struct SingleFile files[10];
    int n, i;

    printf("\nEnter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter file %d name: ", i + 1);
        scanf("%s", files[i].fname);
    }

    printf("\nSingle Level Directory Structure\n");
    printf("ROOT\n");

    for(i = 0; i < n; i++)
    {
        printf(" |-- %s\n", files[i].fname);
    }
}

// ---------- Two Level Function ----------

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

// ---------- Hierarchical Function ----------

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

// ---------- Main Function ----------

int main()
{
    int choice;

    printf("Directory Structure Simulation");

    printf("\n\n1. Single Level Directory");
    printf("\n2. Two Level Directory");
    printf("\n3. Hierarchical Directory");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            singleLevel();
            break;

        case 2:
            twoLevel();
            break;

        case 3:
            hierarchical();
            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}