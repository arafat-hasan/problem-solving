/*****************************************************************************
*   FILE NAME:  The Lazy Lumberjacks-11936.c
*
*   PURPOSE:    Uva
*
*   WRITER: Md. Arafat Hasan Jenin, 1st year 1st semester, CE16024
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* ------------------------------------------------------------------------
*    02 Sep 16      New             1.1         Newly written, accepted
*
******************************************************************************/

#include<stdio.h>
int main() {
    int a,b,c,flag,t;
    scanf("%d",&t);
	while(t){
		while(scanf("%d%d%d",&a,&b,&c)==3) {
			if((a==0)||(b==0)||(c==0))
				flag=0;
			else if(a<0||b<0||c<0)
				flag=0;
			else if(a==b&&b==c)
				flag=1;
			else if((a+b>c)&&(a+c>b)&&(b+c>a))
				flag=1;
			else
				flag=0;
			if(flag)
		    	printf("OK\n");
	    	else
		    	printf("Wrong!!\n");
		}   
		t--;
    }
    return 0;
}
