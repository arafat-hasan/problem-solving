#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
char *strrev(char *str);
void sum(char* a, char* b);
char a[100000], b[100000], c[100000];
int main()
{
    long long t, n, i, e,o=0;
    char d[3];

    d[0]='1', d[1]='\0';

    scanf("%lli", &t);

    while(t--)
    {


        scanf("%lli", &n);
        {


            a[0]='0',a[1]='\0';


if(n!=0)

{


printf("0");

            for(i=1; i < n; i++)
            {    d[0]='1', d[1]='\0';
                sum(a,d);

                strcpy(a,c);
                printf(" %s",c);
            }

            printf(" %i\n",n);}
            else
                printf("0\n");

            o++;

        }


    }

    return 0;
}



void sum(char* a, char* b)
{

    int al, bl, cc, Cs = 0, temp, i;

    al = strlen(a);
    bl = strlen(b);
    strrev(a);
    strrev(b);

    if(al > bl)
    {

        for(i = bl; i < al; i++)
            b[i] = '0';
        b[i] = '\0';
    }

    else
    {

        for(i = al; i < bl; i++)
            a[i] = '0';
        a[i] = '\0';

    }

    cc = i;

    for(i = 0; i < cc; i++)
    {

        temp = a[i] + b[i] - 96 + Cs;
        c[i] = (temp % 10) + 48;
        Cs   = temp / 10;

    }


    if(Cs)
        c[i] = Cs + 48;
    c[i+1] = '\0';
    strrev(c);

}



char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

