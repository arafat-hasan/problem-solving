/***************************************************************************************
*   FILE NAME:  The 3n+1-100,e2.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   29 Sep 16		New         1.0         Completed,Accepted
* 											The 3n+1-100.c
* 	30 Sep 16		Array use	1.1			More faster,Accepted
* 											The 3n+1-100,2e.c
**************************************************************************************/
//Version 1.0, 29 Sep 16
//~ #include <stdio.h>

//~ int main() {

    //~ int a,i,j,st,ed,max,temp;

    //~ while(scanf("%i %i", &st, &ed) == 2) {

        //~ max = 0;

        //~ printf("%i %i ", st, ed);

        //~ if(st > ed) {
            //~ temp = ed;
            //~ ed = st;
            //~ st = temp;
        //~ }

        //~ for(j = st; j <= ed; j++) {

            //~ i=1;
            //~ a=j;

            //~ while(a > 1) {

                //~ i++;

                //~ if(a % 2)
                    //~ a=(3 * a) + 1;

                //~ else
                    //~ a = a / 2;

            //~ }

            //~ if(i > max)
                //~ max = i;


        //~ }

        //~ printf("%i\n", max);

    //~ }

    //~ return 0;
//~ }



//Version 1.1, 30 sep 16
#include <stdio.h>

int main() {

    int a,i,j,st,ed,max,temp,array[1000000];

    while(scanf("%i %i", &st, &ed) == 2) {

        max = 0;

        printf("%i %i ", st, ed);

        if(st > ed) {
            temp = ed;
            ed = st;
            st = temp;
        }

        for(j = st; j <= ed; j++) {

            if(array[j]) {
                i = array[j];
            }

            else {

                i=1;
                a=j;

                while(a > 1) {

                    i++;

                    if(a % 2) {
                        a=(3 * a) + 1;
                    }

                    else {
                        a = a / 2;
                    }

                }

                array[j]=i;

            }

            if(i > max) {
                max = i;
            }

        }

        printf("%i\n", max);

    }

    return 0;
}
