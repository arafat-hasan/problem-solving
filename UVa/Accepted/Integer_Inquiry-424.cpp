/************************************************************************
*   FILE NAME:	Integer Inquiry-424.cpp
*
*   PURPOSE:
*
*   @author:    Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ----------------------------------------------------------------------
*    08 Oct 2016    New             1.0         Completed, Accepted
*************************************************************************/

#include<stdio.h>
#include<string.h>
char *strrev(char *str);
void sum(char* a, char* b);
char a[101], b[103], c[103];

int main() {
    while(scanf("%s", a)==1) {

        if(a[0] == '0'&&a[1] == '\0')
            break;

        sum(a, b);
        strcpy(b, c);

    }

    printf("%s\n", c);

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
