#include<stdio.h>
#include<string.h>
int substring(char txt[20],char pat[20]);
int main()
{
    char txt[20],pat[20];
    int ans=0;
    printf("Enter text\n");
    scanf("%s",txt);
    printf("Enter pattern\n");
    scanf("%s",pat);
    ans=substring(txt,pat);
    if(ans==-1)
    {
        printf("Substring not found\n");
    }
    else
    {
        printf("Substring found at %d",ans);
    }
    return 0;
}
int substring(char txt[20],char pat[20])
{
    int n=strlen(txt),m=strlen(pat),i,j;
    for(i=0;i<n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(txt[i+j]!=pat[j])
                break;

        }
        if(j==m)
            return i;
    }
    return -1;
}
