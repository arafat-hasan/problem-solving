/***************************************************************************************
*   FILE NAME:  Product-10106.c
*
*   PURPOSE:    Solve of Uva problem p10106.
*
*   AUTHOR: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   23 June 16      New         0.0         In-completed
*   03 July 16      Optimized   1.0         Finished
**************************************************************************************/

#include<stdio.h>
int mul_s(int a,int b,int c);
int mul_c(int a,int b,int c);
int sum_s(int a,int b,int c);
int sum_c(int a,int b,int c);

int main() {
    int i,j,k,C,r,xi,yi,Cs,m;
    char x[251],y[251],t[502];
    
    
    while(scanf("%s %s",x,y)==2){
		
        C=0,Cs=0;
        
        
        
        //input
        for(i=0;; i++) {

            
            if(x[i]=='\0') {
                break;
            }

        }
        xi=i-1;
        
        for(i=0;; i++) {

            if(y[i]=='\0') {
                break;
            }

        }
        
        yi=i-1;
        //input end




        for(i=0; i<502; i++) {
            t[i]='0';
        }


        for(j=0; yi>=0; yi--,j++) {
			
            for(i=0,k=xi; k>=0; k--,i++) {
                r= mul_s(x[k]-48,y[yi]-48,C);
                C=mul_c(x[k]-48,y[yi]-48,C);
                m=t[i+j];
                t[i+j]=sum_s(r,m-48,Cs)+48;
                Cs=sum_c(r,m-48,Cs);

            }
            
            t[i+j]=C+Cs+48;
            C=0;
            Cs=0;

        }
        
        
        
		for(k=i+j;k>0;k--){
			if(t[k]!=48){
				t[k+1]=0;
				break;
			}
		}


        for(; k>=0; k--)
            printf("%c",t[k]);
            
        printf("\n");
    }
    
    
    return 0;
    
}
//main() end





int mul_s(int a,int b,int c) {
	
    if(a*b+c>9)
        return (a*b+c)%10;
        
    return a*b+c;
}



int mul_c(int a,int b,int c) {
	
    if(a*b+c>9)
        return (a*b+c)/10;
        
    return 0;
}



int sum_s(int a,int b,int c) {
	
    if(a+b+c>9)
        return (a+b+c)%10;
        
    return a+b+c;
}



int sum_c(int a,int b,int c) {
	
    if(a+b+c>9)
        return (a+b+c)/10;
        
    return 0;
}
