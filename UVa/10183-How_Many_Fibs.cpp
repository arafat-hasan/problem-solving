/*
 * FILE: How_Many_Fibs-10183.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 10-06-17 19:52:58 (+06)
 * LAST MODIFIED: 14-06-17 17:36:13 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 10-06-17     1.0         File Created, Accepted
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
#include <vector>

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define ALL(ar) ar.begin(), ar.end()
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define NL cout << '\n';
#define SP cout << ' ';
#define CHK cout << "##########\n"
#define DEBUG1(x) cout << #x << ": " << x << endl
#define DEBUG2(x, y) cout << #x << ": " << x << "\t" << #y << ": " << y << endl
#define DEBUG3(x, y, z) cout << #x << ": " << x << "\t" << #y << ": " << y << "\t" << #z << ": " << z << endl

#define PB push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646
#define MOD 1000000007
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/

void fibbonacci(int f);
void sumofstr(char *a, char *b, char *c);
int sum_c(int a, int b, int c);
int sum_s(int a, int b, int c);
int binarysearch(int lo, int hi, ll x );
int string_num_cmp(char *str1, char *str2);
char *strrev(char *str);
char fib[500][2000];

int main() {

    fibbonacci(500);
    int cnt;
    char a[105], b[105];
    while (cin >> a >> b) {
        if (strcmp(a, "0") == 0 && strcmp(b, "0") == 0) break;
        if (strcmp(a, "0") == 0 && strcmp(b, "1") == 0) {
            cout << "1\n";
            continue;
        }

        cnt = 0;
        REP(i, 500) {
            if ((string_num_cmp(&fib[i][0], a) == 1 && \
                    string_num_cmp(&fib[i][0], b) == -1) || \
                    string_num_cmp(&fib[i][0], a) == 0 || \
                    string_num_cmp(&fib[i][0], b) == 0)
                cnt++;
        }
        if (strcmp(a, "1") == 0 || strcmp(b, "1") == 0) cnt--;
        if (strcmp(a, "0") == 0) cnt -= 2;
        cout << cnt << '\n';
    }
    return 0;
}

int string_num_cmp(char *str1, char *str2) {
// if str1 > str2, return +1, else if str1 < str2 return -1, else 0
    int len1 = (int) (int) strlen(str1),
        len2 = (int) (int) strlen(str2),
        i;
    if (len1 > len2) {
        return 1;
    } else if (len1 < len2) {
        return -1;
    } else {
        for (i = 0; i < len1; i++) {
            if (str1[i] > str2[i]) return 1;
            else if (str1[i] < str2[i]) return -1;
        }
        if (i == len1) {
            return 0;
        }
    }
    return 0;
}

void fibbonacci(int f) {
    fib[0][0] = '0';
    fib[0][1] = '\0';
    fib[1][0] = '1';
    fib[2][0] = '1';
    fib[1][1] = '\0';
    fib[2][1] = '\0';
    FOR(i, 3, f) {
        sumofstr(&fib[i - 1][0], &fib[i - 2][0], &fib[i][0]);
    }
}

void sumofstr(char *a, char *b, char *c) {

    int len_a, len_b, i, j, k, carry;
    len_a = (int) strlen(a);
    len_b = (int) strlen(b);

    carry = 0;
    for (k = 0, i = len_a - 1, j = len_b - 1; i >= 0 && j >= 0; j--, i--, k++) {
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


    if (carry != 0)
        c[k++] = (char) (carry + 48);
    c[k] = '\0';
    strrev(c);

}


int sum_s(int a, int b, int c) {
    if (a + b + c > 9)
        return (a + b + c) % 10;
    return a + b + c;
}

int sum_c(int a, int b, int c) {
    if (a + b + c > 9)
        return (a + b + c) / 10;
    return 0;
}


char *strrev(char *str) {
    char *p1, *p2;
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + (int) strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
