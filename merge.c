#include<stdio.h>
int b[100];
void mergesort(int a[],int l,int u)
{
  if(l<u)
  {
      int m =(u+l)/2;
      mergesort(a,l,m);
      mergesort(a,m+1,u);
      merge(a,l,m,u);
  }
}
void merge(int a[],int l,int m,int u)
{
    int i=l,j=m+1,k=l;
    //int b[10];
    while(i<=m && j<=u)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    while(j<=u)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    while(i<=m)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    for(k=l;k<=u;k++)
    {
        a[k]=b[k];
    }
}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
main()
{
    int n,i;
    printf("Enter the array size\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n);
    display(b,n);
}
