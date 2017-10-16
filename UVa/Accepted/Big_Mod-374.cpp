/***********************************************************************
*   FILE NAME: Big_Mod-374.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change          Version     Description
* -------------------------------------------------------------------
*    17 Jan 2017    New             1.0         Completed, Accepted
***********************************************************************/

#include <stdio.h>
#include <math.h>
#include <limits.h>
int big_mod(int base, int power, int mod);

int main(){
	
	int b, p, m;
	while(scanf("%d %d %d", &b, &p, &m) == 3){
		printf("%i\n", big_mod(b,p,m));
	}
	
	return 0;
}


int big_mod(int base, int power, int mod){
    if(power==0)    return 1;

    else if(power%2==1) 
    {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0) 
    {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
	return 0;
}
