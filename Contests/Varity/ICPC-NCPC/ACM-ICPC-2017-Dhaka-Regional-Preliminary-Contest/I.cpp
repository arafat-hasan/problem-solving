/*
 * FILE: I.cpp
 *
 * @author: MBSTU_TriO
 *
 * LINK:
 *
 * DATE CREATED: 23-09-17 18:23:14 (BDT)
 * LAST MODIFIED: 23-09-17 19:02:51 (BDT)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-09-17     1.0         File Created
 *
 */

///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <vector>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cout << #x << ": " << x << endl
#define debug2(x, y)    cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000000

////////////////////////// START HERE //////////////////////////

char str[MAX], a[2], a[MAX], b[MAX], c[MAX];

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

int sum_s(int a, int b, int c) { //Used by big_int_sum & big_int_mul
    if (a + b + c > 9) return (a + b + c) % 10;
    return a + b + c;
}
int sum_c(int a, int b, int c) { //Used by big_int_sum & big_int_mul
    if (a + b + c > 9) return (a + b + c) / 10;
    return 0;
}
int mul_s(int a, int b, int c) { //Used by big_int_mul
    if (a * b + c > 9) return (a * b + c) % 10;
    return a * b + c;
}
int mul_c(int a, int b, int c) { //Used by big_int_mul
    if (a * b + c > 9) return (a * b + c) / 10;
    return 0;
}

void big_int_sum(char *a, char *b, char *c) {   // a + b = c

    int len_a, len_b, i, j, k, carry;
    len_a = (int) strlen(a);
    len_b = (int) strlen(b);

    carry = 0;
    k = 0, i = len_a - 1, j = len_b - 1;
    for (; i >= 0 && j >= 0; j--, i--, k++) {
        c[k] = (char) (sum_s(a[i] - 48, b[j] - 48, carry) + 48);
        carry = sum_c(a[i] - 48, b[j] - 48, carry);
    }

    if (i >= 0 && i != j)
        for (; i >= 0; i--, k++) {
            c[k] = (char) (sum_s(a[i] - 48, 0, carry) + 48);
            carry = sum_c(a[i] - 48, 0, carry);
        }

    else if (j >= 0 && i != j)
        for (; j >= 0; j--, k++) {
            c[k] = (char) (sum_s(0, b[j] - 48, carry) + 48);
            carry = sum_c(0, b[j] - 48, carry);
        }


    if (carry != 0) c[k++] = (char) (carry + 48);
    c[k] = '\0';
    strrev(c);

}



void big_int_mul(char *x, char *y, char *t) {

    int i, j, k, C, r, xi, yi, Cs, m;
    C = 0, Cs = 0;

    for (i = 0;; i++) if (x[i] == '\0') break;
    xi = i - 1;

    for (i = 0;; i++) if (y[i] == '\0') break;
    yi = i - 1;

    for (i = 0; i < 502; i++) t[i] = '0';

    for (j = 0; yi >= 0; yi--, j++) {
        for (i = 0, k = xi; k >= 0; k--, i++) {
            r = mul_s(x[k] - 48, y[yi] - 48, C);
            C = mul_c(x[k] - 48, y[yi] - 48, C);
            m = t[i + j];
            t[i + j] = (char) (sum_s(r, m - 48, Cs) + 48);
            Cs = sum_c(r, m - 48, Cs);
        }

        t[i + j] = (char) (C + Cs + 48);
        C = 0;
        Cs = 0;
    }

    for (k = i + j; k > 0; k--) {
        if (t[k] != 48) {
            t[k + 1] = 0;
            break;
        }
    }

    t[k + 1] = 0;
    strrev(t);
}



unsigned long long big_int_div(char *a, unsigned long long b, char *c) {

    int la;
    int i, k = 0, flag = 0;
    unsigned long long temp = 1, reminder;
    la = (int) strlen(a);

    for (i = 0; i <= la; i++) a[i] = (char) (a[i] - 48);

    temp = a[0];
    reminder = a[0];
    for (i = 1; i <= la; i++) {
        if (b <= temp) {
            c[k++] = (char) (temp / b);
            temp = temp % b;
            reminder = temp;
            temp = temp * 10 + a[i];
            flag = 1;
        } else {
            reminder = temp;
            temp = temp * 10 + a[i];
            if (flag == 1) c[k++] = 0;
        }
    }

    for (i = 0; i < k; i++) {
        c[i] = (char) (c[i] + '0');
    }
    c[i] = '\0';
    if (i == 0) {
        c[i] = '0';
        c[1] = '\0';
    }
    return reminder;
}

//int less_great(char a[], char b[]){
//    if(strlen(a) < strlen(b)){
//        return 0;
//    }
//    if(strlen(a) == strlen(b)){
//        int sz = strlen(a);
//        for(int i = 0; i < sz; i++){
//            if(a[i] < b[i]) return 0;
//        }
//    }
//    return 1;
//}

void sod(char s[]) {
    a[1] = '\0';
    str[1] = '\0'; str[0] = '0';
    int sz = strlen(s);
    for (int i = 0; i < sz; i++) {
        a[0] = s[i];
        big_int_sum(str, a, str);
    }
    sz = strlen(str);
    for (int i = 0; i < sz; i++) {
        s[i] = str[i];
    }
}

void f(char s[]) {
    while (strlen(s) > 1) {
        sod(s);
    }
    return ;
}

int main() {
    __FastIO;
    int t;
    char a[MAX], b[MAX];
    cin >> t;
    while (t--) {
        cin >> a >> b;
        for(int )    
    }
    return 0;
}

