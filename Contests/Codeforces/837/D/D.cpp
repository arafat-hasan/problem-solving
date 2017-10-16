/*
 * FILE: D.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03-08-17 22:27:35 (BST)
 * LAST MODIFIED: 04-08-17 00:12:41 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 03-08-17     1.0         File Created
 *
 */


/*
//     ___          ___           ___                       ___
//    /  /\        /  /\         /__/\        ___          /__/\
//   /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
//  /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
//  \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
//     \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
//      \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
//      /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
//     /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
//     \__\/      \  \::/       \  \:\         \__\/      \  \:\
//                 \__\/         \__\/                     \__\/
*/

/////////////////////////////////////////////////////////////////////////////

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

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

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
#define EPS             1e-10
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

char t[MAX];
char x[MAX], y[MAX];

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

void big_int_mul(void)  {

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

void multiplication(vector<string> v) {
    strcpy(y, v[0].c_str());
    int len = (int) v.size();
    for (int i = 1; i < len; i++) {
        strcpy(x, v[i].c_str());
        big_int_mul();
        strcpy(y, t);
    }
}

int count_0(void) {
    int len = (int) strlen(t);
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        if (t[i] != '0') {
            return j;
        }
    }
    return len;
}

int main() {
    // Idea is almost correct, for subset, not subsecuence
    __FastIO;
    int n, k, max = -INF;
    cin >> n >> k;
    vector<string> v(n);
    Rep(i, n) cin >> v[i];
    //Rep(i, n) debug1(v[i]);
    //chk;
    for (int i = 0; i < n; i++) {
        vector<string> send;
        for (int j = i, cnt = 0; cnt < k; j++) {
            if (j == n) j = 0;
            send.pb(v[j]);
            cnt++;
        }
        //for(int k = 0; k < send.size(); k++){
        //    debug1(send[k]);
        //}
        //chk;
        multiplication(send);
        cout << t << '\n';
        int zero = count_0();
        if (zero > max) max = zero;
    }
    cout << max + 1 << '\n';
    return 0;
}

