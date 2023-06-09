#include<stdio.h>
#include<stdlib.h>
int findmin(int a[],int n);
int findmin(int a[],int n)
{
    int i,min=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
        }
    }
    return min;
}
main()
{
    int i,n,min=INT_MAX;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    min=findmin(a,n);
    printf("Minimum element in the array is %d\n",min);
}
