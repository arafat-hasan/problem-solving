i/*
 * FILE: Less_Prime-10852.cpp
 * 
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 * 
 * LINK: https://uva.onlinejudge.org/external/108/10852.pdf
 * 
 * Description: 
 * 
 * 
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    28 Jan 2017    New             1.0         Completed, AC        
 * 
 * 
 */


#include <iostream>
#include <cmath>
using namespace std;

void sieve(int n);

#define maxS 10000

int primelst[maxS]; //for sieve

int main() {


    int n, t, i;
    sieve(maxS);
    cin >> t;
    while(t--){
        cin >> n;
        for(i = n/2; i <= n; i++){
            if(!primelst[i] && (i*2) > n){
                cout << i << endl;
                break;
            }
        }
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

}

