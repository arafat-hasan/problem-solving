/*
 * FILE: Twin Primes-10394.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/103/10394.pdf
 *
 * Description: UVa Problem
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    28 Jan 2017    New             1.0		Completed, AC
 *
 *
 */


#include <iostream>
#include <cmath>

using namespace std;

void sieve(int n);

#define maxS 100000000

int prime[maxS], primelst[maxS], maxprime; //for sieve
int twin_prime[10000000];

int main() {

    sieve(maxS);

    int n;
    
    for(int  i = 0, j = 0; i<maxprime; i++)
        if(prime[i+1] - prime[i] == 2) twin_prime[j++] = prime[i];

    while(cin >> n) {
        cout << "(" <<twin_prime[n-1] << ", " << twin_prime[n-1]+2 <<")"<<endl;
    }
    
    return 0;
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
