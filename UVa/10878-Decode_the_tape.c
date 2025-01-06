/******************************************************************************
*   FILE NAME: Decode the tape-10878.c
*
*   PURPOSE: Solve of Uva problem p10878.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change              Version     Description
* ------------------------------------------------------------------------
*   24 June 16      New                 1.0         Completed, not submitted
*   26 June 16      More Efficient      1.1         Make memory management &
* 													algorithm more efficient
*   26 Sep 16		OJ Runtime error	1.2         Accepted
* 					removed      
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int b2d(int num) {
    int rem,decimal_val=0,base=1;
    
    while(num>0) {
        rem=num%10;
        decimal_val=decimal_val+rem*base;
        num=num/10;
        base=base*2;
    }
    
    return decimal_val;
}


int main() {
    int i=0,j,k,l,m;
    char c[120000],t[10],f[10000];

    //Input
    scanf("%*c%*c%*c%*c%*c%*c%*c%*c%*c%*c%*c%*c");
    
        while(scanf("%c",&c[i])==1) {
        if(c[i]=='_')
            break;
        i++;
        }



    //'o' to '1' convert
    for(k=0; c[k]!='_'; k++) {
        if(c[k]=='o')
            c[k]='1';
        else if(c[k]==' ')
            c[k]='0';
    }
    
    scanf("%*c%*c%*c%*c%*c%*c%*c%*c%*c%*c");


    
    for(l=0,m=0;l<k;l+=12,m++) {
        for(j=l+1,i=0; j<l+6;i++, j++) {//omitting '.' start
            t[i]=c[j];
        }j++;							//make #10010101# format to send it b2d fun
        for(; j<l+10; i++,j++) {
            t[i]=c[j];
        }								//omitting '.' end
        t[i]='\0';						//seal the string
        
        f[m]=b2d(atoi(t));				//convert string to decimal
    }
    
    f[m]='\0';
    
	printf("%s",f);
	
    return 0;
}
