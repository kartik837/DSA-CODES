#include<stdio.h>
int fact(int n)
{
    int ans=1;
    while(n>=1)
    {
       ans=ans*n;
       n--;
    }
    return ans;
}
void percom(int n,int r)
{
    if(n>=r)
    {
        int per=(fact(n))/(fact(n-r));
        int com=(fact(n))/(fact(n-r)*fact(r));
        printf("%d is the permutation\n%d is the combination\n",per,com);
    }
    else
    {
        printf("Permutation and combination not possible with these numbers\n");
    }
}
main()
{
    int n,r;
    printf("Enter number whose permutation and combination is to be found\n");
    scanf("%d%d",&n,&r);
    percom(n,r);
}
