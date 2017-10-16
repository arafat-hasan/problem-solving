#include<stdio.h>
int main()
{
    long long x,y,i,j=0,T, q=0;
    char a[100000];
    scanf("%lld",&T);
    while(j<T)
    {
        scanf("%lld%lld\n",&x,&y);
        gets(a);
        i=0;
        s:
        while(a[i]!=0)
        {
             switch(a[i])
            {
            case 'N':
            case 'n':
                y=y+a[i+1]-48;
                break;
            case 'S':
            case 's':
                y=y-a[i+1]+48;
                break;
            case 'E':
            case 'e':
                x=x+a[i+1]-48;
                break;
            case 'W':
            case 'w':
                x=x-a[i+1]+48;
                break;
            default:
               q++;
            }
            i=i+2;
            if(i==4094)
                i=0;

        }

        printf("%lld %lld##%lld##%lld###\n",x,y,q,i);
        j++;
    }
    return 0;
}
