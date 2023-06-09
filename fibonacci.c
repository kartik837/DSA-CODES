#include<stdio.h>
void fib(int n)
{
   int f1=0,f2=1,f3=1;
   int i;
   printf("%d %d %d ",f1,f2,f3);
   for(i=0;i<n-3;i++)
   {
       f1=f2;
       f2=f3;
       f3=f1+f2;
       printf("%d ",f3);
   }
}
main()
{
    int n;
    printf("Enter the number of fib series\n");
    scanf("%d",&n);
    fib(n);
}
//dynamic logic 1
