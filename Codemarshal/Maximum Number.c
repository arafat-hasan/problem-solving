#include<stdio.h>
main()
{
    int a,b,c,i=0,T;
    scanf("%d",&T);
    while(i<T)
    {
        scanf("%d%d%d",&a,&b,&c);
        printf("Case %d: ",i+1);
        if((a==b)&&(b==c))      /*check if the numbers are equal*/
            printf("%d\n",a);
        else if(a>b)
        {
            if(a>c)
                printf("%d\n",a);
            else
                printf("%d\n",c);
        }
        else if(b>c)
            printf("%d\n",b);
        else
            printf("%d\n",c);
        i++;
    }
    return 0;

}

