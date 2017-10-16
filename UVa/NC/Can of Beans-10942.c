/***************************************************************************************
*   FILE NAME:  Can of Beans-10942.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   26 Sep 16      New         1.0        Not-completed
**************************************************************************************/


#include <stdio.h>

int IsLeapyear(long long year);
void chkdt(void);
void acchk(void);
int max(void);
long long array[6][4];

int main() {

    long long c,x,y,z,a,t,i,j;
    scanf("%lli",&t);
    while(t&&scanf("%lli %lli %lli %lli",&c,&x,&y,&z)==4) {
		
        t--;
		array [0][0] =1;	array [0][1] =x+c;	array [0][2] =y;	array [0][3] =z;	
		array [1][0] =1;	array [1][1] =y+c;	array [1][2] =z;	array [1][3] =x;	
		array [2][0] =1;	array [2][1] =z+c;	array [2][2] =x;	array [2][3] =y;	
		array [3][0] =1;	array [3][1] =z+c;	array [3][2] =y;	array [3][3] =x;	
		array [4][0] =1;	array [4][1] =x+c;	array [4][2] =z;	array [4][3] =y;	
		array [5][0] =1;	array [5][1] =y+c;	array [5][2] =x;	array [5][3] =z;	


        for(i=0; i<6; i++) {
            for(j=0; j<4; j++)
                printf("%lli\t",array[i][j]);
            printf("\n");
        }
        printf("chdtt\n");
        chkdt();

        for(i=0; i<6; i++) {
            for(j=0; j<4; j++)
                printf("%lli\t",array[i][j]);
            printf("\n");
        }

        printf("acchkk\n");
        acchk();

        for(i=0; i<6; i++) {
            for(j=0; j<4; j++)
                printf("%lli\t",array[i][j]);
            printf("\n");
        }

        printf("maxx\n");
        a=max();


        for(i=0; i<6; i++) {
            for(j=0; j<4; j++)
                printf("%lli\t",array[i][j]);
            printf("\n");
        }

        if(a==-1)
            printf("-1\n");
        else
            printf("%02lli %02lli %02lli\n",array[a][1]-c,array[a][2],array[a][3]);


    }

    return 0;

}



void chkdt(void) {
    int i;
    for(i=0; i<6; i++)
        if((array[i][2]>12||array[i][2]<1)||(array[i][3]>31||array[i][3]<1)) {
            array[i][0]=0;
            printf("#chkdt%i\n",i);
        }

}


void acchk(void) {
    int i,y;
    for(i=0; i<6; i++) {
        if(array[i][0]==1) {

            if(array[i][2]==1||array[i][2]==3||array[i][2]==5||array[i][2]==7||array[i][2]==8||array[i][2]==10||array[i][2]==12) {
                if(array[i][3]>31)
                    array[i][0]=0;
                printf("#acchkq%i\n",i);

            }

            else if(array[i][2]==2) {
                y=IsLeapyear(array[i][1]);
                printf("yyyy%i",y);
                if(y) {
                    if(array[i][3]>29)
                        array[i][0]=0;
                    printf("#acchkw%i\n",i);
                }


                else {
                    if(array[i][3]>28)
                        array[i][0]=0;
                    printf("#acchke%i\n",i);
                }

            }

            else {

                if(array[i][3]>30)
                    array[i][0]=0;
                printf("#acchk%i\n",i);
            }

        }

    }

}



/*Leap Year Checking*/
int IsLeapyear(long long year)
{

    /*Is year divided by 4? After every 100 years a leap year is not counted
    and after every 400 years we count leap year*/

    if((((year%4)==0)&&((year%100)!=0))||((year%400)==0))
        return 1;
    else
        return 0;

}



int max(void) {
    long long i,min,j,c,k;

    for(j=1; j<4; j++) {
        k=0;
        min=99999999999999;
        for(i=0; i<6; i++) {

            if(array[i][0]!=0) {




                if(array[i][j]<min) {


                    min = array[i][j];
                    if(k)
                        array[c][0]=0;
                    c=i;
                    printf("minnn%lli\n",min);
                    k++;
                }


                else {
                    if(array[i][j]!=min)
                        array[i][0]=0;
                    printf("#mx%lli\n",i);
                }

            }

        }



    }

    for(i=0; i<6; i++)
        if(array[i][0]==1)
            return i;

    return -1;

}
