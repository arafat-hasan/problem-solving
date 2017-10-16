/***************************************************************
*   FILE NAME:  A - Largest Prime Divisor.cpp
*
*   PURPOSE:
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------
*   23 Jan 16      New         1.0         Completed, TLE
*****************************************************************/


#include <iostream>
#include <cmath>

using namespace std;

#define maxS 100000000

void sieve(int n);
int primefact(long long n);
int prime[maxS], primelst[maxS], fact[100][2], maxprime;

int main() {

    int n, numofprimefactor;
    sieve(maxS);

    while(cin >> n) {

        if(n==0)
            return 0;
        else if(primelst[n]==0||n==1)
            cout << "-1" << endl;
        else {
            numofprimefactor=primefact(n);
            cout << fact[numofprimefactor-1][0]<< endl;
        }
    }

    return 0;
}


int primefact(long long n) {

    long long i,j;

    if(n==0||prime[n]==0)
        return 0;

    for(i=0, j=0; i < maxprime; i++) {
        if(n%prime[i]==0) {
            fact[j][0]=prime[i];
            fact[j][1]=0;
            while(n%prime[i]==0) {
                n/=prime[i];
                fact[j][1]++;
            }
            j++;
        }
    }

    if(j==0) {
        fact[0][0]=n;
        fact[1][1]=1;
        j++;
    }
    return j;

}




void sieve(int n) {

    int i,j;
    double root=sqrt(n);

    primelst[0]=primelst[1]=1;

    for(i=4; i<n; i+=2)
        primelst[i]=1;

    for(i=3, j=0; i<=root; i+=2) {
        if(!primelst[i]) {
            for(j=i*i; j<n; j+=2*i)
                primelst[j]=1;
        }
    }


    for(i=0, j=0; i<n; i++) {
        if(primelst[i]==0) {
            prime[j++]=i;
        }
    }

    maxprime=j;

}
