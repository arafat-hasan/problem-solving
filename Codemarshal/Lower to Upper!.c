#include<stdio.h>
#include<ctype.h>
int main()
{
    int i,j,T;
    char str[101];
    scanf("%d",&T);
    for(i=0; i<=T; i++)
    {
        if(i==0)
        {
            gets(str);
            printf("%s",str);
            continue;
        }
        gets(str);
        printf("Case %d: ",i);
        for(j=0; str[j]!='\0'; j++)
        {
            str[j]=toupper(str[j]);
        }
        printf("%s\n",str);

    }
    return 0;
}
