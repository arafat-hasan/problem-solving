#include <stdio.h>
int array[1073741825];
int main()
{
    int n,t,o,i, max;
    scanf("%i", &t);
    o=1;
    while(o<=t)
    {

        scanf("%i", &n);
        int tmp[n];
        for(i=0; i<n; i++)
        {

            scanf("%i", &tmp[i]);
             array[tmp[i]]=0;

        }

        max=-99999;

        for(i=0; i<n; i++)
        {
            array[tmp[i]]++;
            if(array[tmp[i]]>max)
                max=array[tmp[i]];


        }
        printf("Case %i: %i\n", o,max);



        o++;
    }





    return 0;
}



void sum(char* a, char* b) {

    int al, bl, cc, Cs = 0, temp, i;

    al = strlen(a);
    bl = strlen(b);
    strrev(a);
    strrev(b);

    if(al > bl) {

        for(i = bl; i < al; i++)
            b[i] = '0';
        b[i] = '\0';
    }

    else {

        for(i = al; i < bl; i++)
            a[i] = '0';
        a[i] = '\0';

    }

    cc = i;

    for(i = 0; i < cc; i++) {

        temp = a[i] + b[i] - 96 + Cs;
        c[i] = (temp % 10) + 48;
        Cs   = temp / 10;

    }


    if(Cs)
        c[i] = Cs + 48;
    c[i+1] = '\0';
    strrev(c);

}
