/*
 * FILE: If_We_Were_a_Child_Again-10494.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
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
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define nl cout << endl

#define INF 500000000
#define maxN 32001
#define PI acos(-1.0)
#define maxS 100000000


typedef long long ll;
using namespace std;


/**************************Big Number*******************************/

uint64 BIG_INT_DIV(char *a, uint64 b, char *c) {

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

/**************************Big Number End***************************/



int main() {

    uint64 divisor, rem;
    char a[1000], c[1000], op;
    while(cin >> a) {
        do {
            cin >> op;
        } while(!(op == '%' || op == '/'));

        cin >> divisor;
        rem = BIG_INT_DIV(a, divisor, c);
        if(op == '%') cout << rem << endl;
        else cout << c << endl;

    }
    return 0;
}


