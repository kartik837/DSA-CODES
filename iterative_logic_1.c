//Sum of rows in an 2d arrays...
#include<stdio.h>
#include<stdlib.h>

void read(int a[100][100],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void display(int a[100][100],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int r,c,a[100][100];
    int sum=0;
    printf("enter the number of rows and columns:\n");
    scanf("%d%d",&r,&c);
    printf("enter each elements:\n");
    read(a,r,c);
    printf("The matrix is :\n");
    display(a,r,c);
    printf("the sum of each rows is given as :\n");
    for(int i=0;i<r;i++)
    {
        sum = 0;
        for(int j=0;j<c;j++)
        {
            sum = sum+a[i][j];
        }
        printf("the sum of row %d is = %d\n",i,sum);
    }

    return 0;

}
