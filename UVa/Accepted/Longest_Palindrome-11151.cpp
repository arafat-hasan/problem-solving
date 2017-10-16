/*
 * FILE: Longest_Palindrome-11151.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 07-06-17 04:15:45 (+06)
 * LAST MODIFIED: 07-06-17 17:41:44 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 07-06-17     1.0         File Created, Accepted
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

//int dp[1005][1005];
//// Returns the length of the longest palindromic subsequence in seq
//int lps(string seq, int i, int j) {
//    // Base Case 1: If there is only 1 character
//    if (i == j)
//        return 1;

//    // Base Case 2: If there are only 2 characters and both are same
//    if (seq[i] == seq[j] && i + 1 == j)
//        return 2;

//    if (dp[i][j] != -1) return dp[i][j];

//    // If the first and last characters match
//    if (seq[i] == seq[j])
//        return dp[i][j] = lps(seq, i + 1, j - 1) + 2;

//    // If the first and last characters do not match
//    return dp[i][j] = max(lps(seq, i, j - 1), lps(seq, i + 1, j) );
//}



// Returns the length of the longest palindromic subsequence in seq
int lps_it(string str) {
    short DP[1001][1001];
    memset(DP, 0, sizeof(DP));
    int len = (int) str.length(), i, j;
    for (i = 0; i < len; i++) {
        for (j = 0; j + i < len; j++) {
            if (str[j] == str[i + j]) {
                DP[j][j + i] = (short) (DP[j + 1][j + i - 1] + (i == 0 ? 1 : 2));
            } else {
                DP[j][j + i] = max(DP[j + 1][j + i], DP[j][j + i - 1]);
            }
        }
    }
    return DP[0][len - 1];
}


int main() {
    __FastIO;
    int n;
    string str;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, str);
        cout << lps_it(str) << '\n';
    }
    return 0;
}

