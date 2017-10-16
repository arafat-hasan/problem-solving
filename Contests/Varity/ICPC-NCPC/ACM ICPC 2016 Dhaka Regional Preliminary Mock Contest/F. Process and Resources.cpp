#include <stdio.h>
int rid[20000000], R, P;
int main()
{
    int t, q, qtype,i;


    scanf("%i", &t);
    while(t-- && scanf("%i", &q)==1)
    {

        while(q-- && scanf("%i", &qtype)==1)
        {
            if(qtype==1)
            {
                scanf("%i %i", &P, &R);
                if(rid[R])
                    printf("N\n");
                else{
                    printf("Y\n");
                    rid[R]=P;
                    }

            }
            else
            {
                scanf("%i", &R);
                printf("%lli\n", rid[R]);
                rid[R]=0;
            }





        }

        for(i=0;i<20000000;i++)
            rid[i]=0;


    }

    return 0;
}
