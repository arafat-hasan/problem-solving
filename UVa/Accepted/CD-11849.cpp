/**************************************************************
*   FILE NAME:  CD-11849.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* --------------------------------------------------------------
*   24 Nov 16      New         1.0         Completed,Accepted
***************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    int i, jack, jill, first, last, middle, count;
    int jack_cd[1000000], jill_cd[1000000];

    while(scanf("%i %i", &jack, &jill) == 2 && (jack || jill)) {

        for(i = 0; i < jack; i++) {
            scanf("%i", &jack_cd[i]);
        }

        for(i = 0; i < jill; i++) {
            scanf("%i", &jill_cd[i]);
        }

        count = 0;
        for(i = 0; i < jack; i++) {

            first = 0;
            last = jill - 1;
            middle = (first+last)/2;

            while (first <= last) {

                if (jill_cd[middle] < jack_cd[i])
                    first = middle + 1;
                else if (jill_cd[middle] == jack_cd[i]) {
                    count++;
                    break;
                }
                else
                    last = middle - 1;

                middle = (first + last)/2;
            }


        }
        printf("%i\n", count);

    }



    return 0;
}
