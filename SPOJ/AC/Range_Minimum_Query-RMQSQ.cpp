/*
 * FILE: Range_Minimum_Query-RMQSQ.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://www.spoj.com/problems/RMQSQ/
 *
 * DATE CREATED: 19-05-17 13:27:52 (+06)
 * LAST MODIFIED: 19-05-17 14:05:15 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 19-05-17		1.0         File Created
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
#define Max 10000005

using namespace std;

/********************* Code starts here ************************/

int ST[24][Max];
int A[Max];
void sparse_table(int N) {
    for (int i = 0; i < N; i++) ST[0][i] = i;

    for (int k = 1; (1 << k) < N; k++) {
        for (int i = 0; i + (1 << k) <= N; i++) {
            int x = ST[k - 1][i];
            int y = ST[k - 1][i + (1 << (k - 1))];
            ST[k][i] = A[x] <= A[y] ? x : y;
        }
    }
}

int RMQ(int i, int j) {
    int k = (int) log2(j - i);
    int x = ST[k][i];
    int y = ST[k][j - (1 << k) + 1];
    return A[x] <= A[y] ? x : y;
}

int main() {
    __FastIO;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sparse_table(N);
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        cout << A[RMQ(x, y)] << '\n';
    }
    return 0;
}

