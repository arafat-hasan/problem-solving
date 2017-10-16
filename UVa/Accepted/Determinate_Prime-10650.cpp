/*
 * FILE: Determinate_Prime-10650.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/106/10650.pdf
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

#define maxS 1000000

int prime[maxS], primelst[maxS], maxprime; //for sieve


int main() {

    sieve(maxS);

    int x, y, d1, d2, j, i, det[100], sz;
    while(cin >> x >> y) {

        if(x == 0&& y == 0)
            return 0;

        for(i = 0; i < maxS; i++) {
            if(prime[i] >= x) {
                x = i;
                break;
            }
        }

        for(i = 0; i < maxS; i++) {
            if(prime[i] == y) {
                y = i;
                break;
            }

            else if(prime[i] > y) {
                y = i-2;
                break;
            }
        }

        for(i = x; i <= y; i++) {

            d1 = prime[i+1] - prime[i];
            d2 = prime[i+2] - prime[i+1];
            //printf("%i %i\n", d1, d2);
            if(d1 == d2) {
				sz = 0;
                det[sz++] = prime[i]; det[sz++] = prime[i+1]; det[sz++] = prime[i+2];

                for(j = i+2; j <= y; j++) {
                    if(prime[j+1] - prime[j] != d1)
                        break;
                    det[sz++] = prime[j+1];


                }
//cout<<prime[j+1]<<" "<<j<<endl;
                i = j;sz--;
                if(prime[j+1] - prime[j] != d1 && cc ){
					for(int j = 0; j < sz;j++)
						cout << det[j]<< " ";
					cout <<det[sz]<<endl;
				}
            }
        }
           // cout << endl;
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

/*
0 32000
250 268
252 270
255 269
250 269
251 270
251 269
250 270
0 10
0 0
* 
*/
