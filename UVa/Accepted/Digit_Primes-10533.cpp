/*
 * FILE_NAME: Digit Primes-10533.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    27 Jan 2017    New             1.0		Completed, AC
 *
 *
 */


#include <stdio.h>
#include <math.h>
void sieve(int n);

#define maxS 1000002
int primelst[maxS], dp[maxS]; //for sieve


int main() {

    sieve(maxS);
    int n, t1, t2, sum, count = 0, tmp, i;

    for(i=0; i< maxS; i++) {


        dp[i] = count;

        if(!primelst[i]) {
            sum = 0;
            tmp = i;
            while(tmp>0) {
                sum+=tmp%10;
                tmp/=10;
            }

            if(!primelst[sum]){
                dp[i] = ++count;
            }
        }

    }


    
    scanf("%i", &n);
    while(n--) {
        scanf("%i %i", &t1, &t2);
        if(t1 == t2){
            if(dp[t1] == dp[t1-1])
                printf("0\n");
            else
                printf("1\n");
        }

        else if(dp[t1] == dp[t1-1]+1)
            printf("%i\n", dp[t2]-dp[t1]+1);

        else
            printf("%i\n", dp[t2] - dp[t1]);
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

