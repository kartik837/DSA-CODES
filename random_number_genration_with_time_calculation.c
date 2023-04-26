#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n;
    int temp = 0;
    clock_t st,et;
    FILE *fp3,*fp4,*fp5;

    fp3 = fopen("kar.txt","w");
    fp4 = fopen("har.txt","w");
    fp5 = fopen("hari.txt","w");

    printf("enter the number of random numbers you need to generate:\n");
    scanf("%d",&n);
    int a[n];
    int p = n;
    time_t t;

    srand((unsigned)time(&t));

    fprintf(fp3,"the random numbers are :\n");
    for(int i=0;i<n;i++)
    {
        a[i] =  rand()%10;
        fprintf(fp3,"%d ",a[i]);
    }

     for(int i=n;i>0;i--)
    {
        fprintf(fp5,"%d ",a[i]);
    }
 st = clock();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j+1]>a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for(int i=0;i<p;i++)
    {
        fprintf(fp4,"%d ",a[i]);
    }

et = clock();

    double duration;
    duration = ((double)et-st);

    printf("the time taken for sorting:\n");
    printf("%lf",duration);

    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

   return 0;
}
