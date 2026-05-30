#include <stdio.h>
#include <string.h>

struct SingleFile
{
    char fname[30];
};

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

int main()
{
    printf("Akshay KS\n1BM24CS029\n");
    singleLevel();
    return 0;
}