/*
 * FILE: L - k-th divisor.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://vjudge.net/contest/152547#problem/L
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    02 Mar 2017    New             1.0		NAC
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back


/***************____________BIT_OPERATIONS____________***************/
#define bit(n) (1 << (n))
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << i))? 1 : 0)
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i))//set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) (n ^ ( 1 << i))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define nl cout << endl;
#define chk cout << "##########" << endl;

#define INF INT_MAX
#define MAXN 32001
#define PI acos(-1.0)
#define MAXS 100000000


typedef long long ll;
using namespace std;


vector<int> adj [100]; // for BFS & bfs_vis
int cost[100]; // for BFS & bfs_vis
int visited [100]; //for bfs_vis

int prime[MAXS], maxprime; //for sieve
int fact[100][2]; //for prime factor
//100 will be replaced with max number of factors
bool primelst[MAXS]; //for sieve


int primefactor(long long n) {

    long long i,j;

    if(n==0||primelst[n]==0)
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

    return j;
}


void sieve(int n) {

    int i,j;
    double root = sqrt(n);
    primelst[0] = primelst[1] = 1;

    for(i = 4; i < n; i += 2)
        primelst[i] = 1;

    for(i = 3, j = 0; i <= root; i += 2) {
        if(!primelst[i]) {
            for(j = i*i; j < n; j += 2*i)
                primelst[j] = 1;
        }
    }

    for(i = 0, j = 0; i < n; i++) {
        if(primelst[i] == 0) {
            prime[j++] = i;
        }
    }

    maxprime = j - 1;

}


void swap(int *x, int *y) {
    // Code to swap 'x' and 'y'
    *x = *x * *y; // x now becomes 15
    *y = *x / *y; // y becomes 10
    *x = *x / *y; // x becomes 5
}


long double fibbonacci(long double f) {
    return (pow(((1+sqrt(5))/2),f)-pow(((1-sqrt(5))/2),f)) / sqrt(5);
}


long long factorial(int n) {
    if (n == 0) return 1;
    else return (n * factorial(n - 1));
}


bool isprime(int num) {
    int i, root = sqrt(num);
    if(num < 2) 			return false;
    if(num == 2)			return true;
    if(num % 2 == 0)		return false;

    for(i = 3; i <= root; i += 2)
        if(num % i == 0)	return false;

    return true;
}


int gcd(int a, int b)  {
    if (b == 0) return a;
    else return gcd(b, a % b);
}


int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


int lcm2(int a,int b) {
    int temp = a;
    while(1) {
        if(temp % b == 0 && temp % a == 0) break;
        temp++;
    }
    return temp;
}


char *strrev(char *str) { //Used by big_int_sum & big_int_mul
    char *p1, *p2;
    if (! str || ! *str) return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

/****************************Big Number******************************/
int sum_s(int a,int b,int c) { //Used by big_int_sum & big_int_mul
    if(a+b+c>9) return (a+b+c)%10;
    return a+b+c;
}
int sum_c(int a,int b,int c) { //Used by big_int_sum & big_int_mul
    if(a+b+c>9) return (a+b+c)/10;
    return 0;
}
int mul_s(int a,int b,int c) { //Used by big_int_mul
    if(a*b+c>9) return (a*b+c)%10;
    return a*b+c;
}
int mul_c(int a,int b,int c) { //Used by big_int_mul
    if(a*b+c>9) return (a*b+c)/10;
    return 0;
}

void big_int_sum(char* a, char* b, char* c) {	// a + b = c

    int len_a, len_b, i, j, k, carry;
    len_a = strlen(a);
    len_b = strlen(b);

    carry = 0;
    k = 0, i = len_a-1, j = len_b-1;
    for(; i >= 0 && j >= 0; j--, i--, k++) {
        c[k] = sum_s(a[i]-48, b[j]-48, carry)+48;
        carry = sum_c(a[i]-48, b[j]-48, carry);
    }

    if(i>=0 && i != j)
        for(; i >= 0; i--, k++) {
            c[k] = sum_s(a[i]-48, 0, carry)+48;
            carry = sum_c(a[i]-48, 0, carry);
        }

    else if(j>=0 && i != j)
        for(; j >= 0; j--, k++) {
            c[k] = sum_s(0, b[j]-48, carry)+48;
            carry = sum_c(0, b[j]-48, carry);
        }


    if(carry != 0) c[k++] = carry + 48;
    c[k] = '\0';
    strrev(c);

}



void big_int_mul(char *x, char *y, char *t) {

    int i,j,k,C,r,xi,yi,Cs,m;
    C=0,Cs=0;

    for(i=0;; i++) if(x[i]=='\0') break;
    xi=i-1;

    for(i=0;; i++) if(y[i]=='\0') break;
    yi=i-1;

    for(i=0; i<502; i++) t[i]='0';

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

    for(k=i+j; k>0; k--) {
        if(t[k]!=48) {
            t[k+1]=0;
            break;
        }
    }

    t[k+1] = 0;
    strrev(t);
}



uint64 big_int_div(char *a, uint64 b, char *c) {

    int la;
    int i,k=0,flag=0;
    uint64 temp=1,reminder;
    la=strlen(a);

    for(i=0; i<=la; i++) a[i] = a[i] - 48;

    temp = a[0];
    reminder = a[0];
    for(i=1; i<=la; i++) {
        if(b<=temp) {
            c[k++] = temp/b;
            temp = temp % b;
            reminder = temp;
            temp =temp*10 + a[i];
            flag=1;
        }
        else {
            reminder = temp;
            temp =temp*10 + a[i];
            if(flag==1) c[k++] = 0;
        }
    }

    for(i=0; i<k; i++) {
        c[i]=c[i]+48;
    }
    c[i]= '\0';
    if(i == 0) {
        c[i] = '0';
        c[1] = '\0';
    }
    return reminder;
}

/**************************Big Number End****************************/


bool isleapyear(long int year) {
    /*Is year divided by 4? After every 100 years a leap year is not
    counted and after every 400 years we count leap year*/
    if((((year%4)==0)&&((year%100)!=0)) || ((year%400)==0))
		return true;
    else return false;
}


int big_mod(int base, int power, int mod) {

    if(power==0)    return 1;
    else if(power%2==1) {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0) {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
    return 0;
}


int binarysearch (int *array, int end,int key) {
    //array must be sorted, if key is found return 0 based index,
    //else -1;
    int start = 0, mid;
    end--;
    while (start <= end) {
        mid = (start + end) / 2;
        if (key == array[mid]) return mid;
        else if (key < array[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}


void bubble_sort(int *list, int n) {
    int c, d, t;
    for (c = 0 ; c < ( n - 1 ); c++) {
        for (d = 0 ; d < n - c - 1; d++) {
            if (list[d] > list[d+1]) {
                /* Swapping */
                t         = list[d];
                list[d]   = list[d+1];
                list[d+1] = t;
            }
        }
    }
}


void insertion_sort(int *array, int n) {
    int t, d, c;
    for (c = 1 ; c <= n - 1; c++) {
        d = c;

        while ( d > 0 && array[d] < array[d-1]) {
            t          = array[d];
            array[d]   = array[d-1];
            array[d-1] = t;

            d--;
        }
    }
}




void merge(int *a, int low, int high, int mid) { //used by merge_sort

    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) a[i] = c[i];
}

void merge_sort(int *a, int low, int high) { //low and high inclusive

    int mid;
    if (low < high) {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}

int max(int a, int b) {
    return (a < b)? b : a;
}

int main() {

    /*Code Here*/
    return 0;

}



/*********************************************************************
__________________________BUILT_IN FUNCTIONS__________________________


#
int sprintf(char *restrict buffer, const char *restrictformat, ...);
This function convert number to string with specified format.
Defined in header <stdio.h>
Example:
int aInt = 368;
char str[15];
sprintf(str, "%d", aInt);
cout << str << endl;


#
std::cin.getline();
getline can be provided a third argument--a "stop" character. This
character ends getline's input. The character is eaten and the
string is terminated. Example: std::cin.getline(str, 100, '|')
If std::cin.getline() is not provided a "stop" character as a third
argument, it will stop when it reaches a newline.
Example: std::cin.getline(str, 100)


#
std::cin.ignore()
can be called three different ways:
1. No arguments: A single character is taken from the input buffer
and discarded:
std::cin.ignore(); //discard 1 character
2. One argument: The number of characters specified are taken from
the input buffer and discarded:
std::cin.ignore(33); //discard 33 characters
3. Two arguments: discard the number of characters specified, or
discard characters up to and including the specified delimiter
(whichever comes first):
std::cin.ignore(26, '\n');
//ignore 26 characters or to a newline, whichever comes first



#
Formated I/O
Example: std::cout << std::right << setw(5) << 123 << endl;
//output:"  123"
std::cout.fill('X');
std::cout << setw(2) << one << std::endl.;
//output: "X4"
#include <iomanip>


#
strcpy(char* des, char* src) //Copies src into des.


#
double a = 18.12385;
cout << fixed << setprecision(3);
cout << a << endl;
//output: 18.124
#include <iomanip>
std::fixed, std::setprecision()


#
next_permutation(str, str+strlen(str));
return non-zero if next permutation found, otherwise 0
    char str[] = "arafat";
    if(next_permutation(str, str+strlen(str)))
        cout << str << endl;
//output: arafta
#include <algorithm>



 ********************************************************************/
