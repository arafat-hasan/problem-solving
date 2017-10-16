#include <stdio.h>
#include <math.h>


#include <map>
#include <iostream>
using namespace std;

#define long long long
const long M = 1000000007; // modulo
map<long, long> F;



long long fib(long n);

int main()
{
    long long t, n, k, o=1;
    long long ans,m ;
    scanf("%lli", &t);

    while(o <= t)
    {
        scanf("%lli %lli %lli", &n, &k, &m);
        ans = (long long)(pow(k, fib(n)))% m;
        printf("Case %lli: %lli\n", o, ans);
        o++;
    }

    return 0;
}



/*long long fib(long long n1)
{
    long double n,f;
    n=n1+2;
    f=((pow(((1+sqrt(5))/2),n))-(pow(((1-sqrt(5))/2),n)))/sqrt(5);
    return (long long)f;
}*/


long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}

long long fib(long n){

	F[0]=F[1]=1;

n==0 ? return  0 : return f(n-1);
}
