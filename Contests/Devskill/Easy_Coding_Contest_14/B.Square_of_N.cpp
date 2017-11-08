/*
 * FILE: B.Square_of_N.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 04-11-17 22:22:32 (+06)
 * LAST MODIFIED: 04-11-17 22:31:35 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 04-11-17     1.0         {{File Created}}
 *
 *
 *                 _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *                _/  _/        _/_/    _/    _/    _/_/    _/
 *               _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *        _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *         _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

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

//void big_int_sum(char *a, char *b, char *c) {   // a + b = c

//    int len_a, len_b, i, j, k, carry;
//    len_a = (int) strlen(a);
//    len_b = (int) strlen(b);

//    carry = 0;
//    k = 0, i = len_a - 1, j = len_b - 1;
//    for (; i >= 0 && j >= 0; j--, i--, k++) {
//        c[k] = (char) (sum_s(a[i] - 48, b[j] - 48, carry) + 48);
//        carry = sum_c(a[i] - 48, b[j] - 48, carry);
//    }

//    if (i >= 0 && i != j)
//        for (; i >= 0; i--, k++) {
//            c[k] = (char) (sum_s(a[i] - 48, 0, carry) + 48);
//            carry = sum_c(a[i] - 48, 0, carry);
//        }

//    else if (j >= 0 && i != j)
//        for (; j >= 0; j--, k++) {
//            c[k] = (char) (sum_s(0, b[j] - 48, carry) + 48);
//            carry = sum_c(0, b[j] - 48, carry);
//        }


//    if (carry != 0) c[k++] = (char) (carry + 48);
//    c[k] = '\0';
//    strrev(c);

//}



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

int main() {
    __FastIO;
    char nines[105], copy[105], ans[1000];
    while (cin.getline(nines, 105)) {
        strcpy(copy, nines);
        big_int_mul(nines, copy, ans);
        cout << ans << endl;
    }
    return 0;
}

