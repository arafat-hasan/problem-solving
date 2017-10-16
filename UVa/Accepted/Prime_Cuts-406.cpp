/*
 * FILE: Prime_Cuts-406.cpp
 * 
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 * 
 * LINK: https://uva.onlinejudge.org/external/4/406.pdf
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

#define maxS 1000000
void sieve(int n);
int prime[maxS], primelst[maxS], maxprime; //for sieve


int main() {
    int i, n , c, count, half, container;
    sieve(maxS);
    while(cin >> n >> c){
       count = 0;
       container = c;
        for(i = 0;prime[i] <= n; i++){
            count++;
         }
       
       if(count%2 != 0){
            half = ((count-1)/2) - (c-1);
            c = 2 * c - 1;
        }


        else{
            half = (count/2) - (c);
            c *= 2;
       }

        if(half<0 || c > count){    
            half = 0;
            c = count;
        }

        cout << n << " " << container << ": ";
        for(i = half; i < c+half-1; i++){
          cout << prime[i] << " ";        
        }
        
        cout << prime[i] << endl << endl;
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

    primelst[1] = 0; //1 is prime in these problem
    for(i=0, j=0; i<n; i++) {
        if(primelst[i]==0) {
            prime[j++]=i;
        }
    }

    maxprime=j;

}

