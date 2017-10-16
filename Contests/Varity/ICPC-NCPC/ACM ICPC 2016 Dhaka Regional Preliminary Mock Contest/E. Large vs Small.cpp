#include <stdio.h>

int main()
{

    int array[100], n, t=0, max, min, i;

    scanf("%i", &n);


    while(t<n)
    {

        scanf("%i", &array[t]);

        max= -99999999;
        min = 99999999;


        for(i=0; i<=t; i++)
        {

            if(array[i] > max)
                max = array[i];

            if(array[i]<min)
                min = array[i];


        }

        t++;

        printf("Case %i: %.2f\n", t, (float)max/min);


    }

    return 0;
}
