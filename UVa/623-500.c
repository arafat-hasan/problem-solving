/***************************************************************************************
*   FILE NAME:  500!-623.c
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ------------------------------------------------------------------------
*   26 Sep 16      New         1.0         Completed,Accepted
**************************************************************************************/

#include<stdio.h>
int mul_s(int a,int b,int c);
int mul_c(int a,int b,int c);
int sum_s(int a,int b,int c);
int sum_c(int a,int b,int c);
void multi(void);
void str2int(int n, char* c);
char x[2700],y[1002],a[1000][2700];
int fact;

int main(){
	int n,i;
	x[0]='1',x[1]='\0';
	
	
	for(fact=1;fact<=1000;fact++){
		str2int(fact,y);
		multi();
			
	}


	while(scanf("%d",&n)==1){
		
		printf("%d!\n",n);
		if(n<=0)
			printf("1");
		else{
			for(i=0;;i++){
				
				if(a[n][i]=='\0')
					break;
				printf("%c",a[n][i]);
				
			}
		}
			printf("\n");
		}
	
	
	return 0;
	
}



/*
 *str2int() function convert integer number to string
 * Prototype void str2int(int n, char* c)
 * n is the number to convert, c is pointer of the char
 * array to store the string
 * */

void str2int(int n, char* c) {
  
	int reverse = 0, temp,i=0;
        
    temp = n;
        
    while( temp != 0 ) {
		reverse = reverse * 10;
		reverse = reverse + temp%10;
		temp = temp/10;
    }
        
	
    temp=reverse;

	while( temp != 0 ) {
        c[i] = temp%10+48;
        temp = temp/10;
        i++;
    }
     
     
	if(n%10==0)
        while(n!=0){
			
			if(n%10==0)
			c[i]='0';
			i++;
			n=n/10;
			if(n%10)
			break;
		}
        
        c[i]='\0';


}





void multi(void) {
	
    int i,j,k,C,r,xi,yi,Cs,m;
	char t[5000];
	
	
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




    for(i=0; i<5000; i++) {
        t[i]='0';
    }



    for(j=0; yi>=0; yi--,j++) {
			
        for(i=0,k=xi; k>=0; k--,i++) {
            r=mul_s(x[k]-48,y[yi]-48,C);
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
			t[k+1]='\0';
			break;
		}
		
	}


    for(i=0; k>=0; k--,i++){
        x[i]=t[k];
        a[fact][i]=t[k];
    }

    a[fact][i]='\0';
    x[i]='\0';
            
}



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
