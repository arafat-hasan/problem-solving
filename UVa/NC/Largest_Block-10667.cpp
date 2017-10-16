/*
 * FILE: Largest_Block-10667.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 13-06-17 22:55:57 (+06)
 * LAST MODIFIED: 14-06-17 03:55:16 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 13-06-17     1.0         File Created
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

#define FOR(i, a, b) for (ll i=a; i<=b; i++)
#define ROF(i, b, a) for (ll i=b; i>=a; i--)
#define REP(i, n) for (ll i=0; i<n; i++)
#define ALL(ar) ar.begin(), ar.end()
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) prllf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) prllf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) prllf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) prllf("%d", a)
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


// Implementation of Kadane's algorithm for 1D array. The function
// returns the maximum sum and stores starting and ending indexes of the
// maximum sum subarray at addresses polled by start and finish pollers
// respectively.
ll kadane(ll *arr, ll *start, ll *finish, ll n) {
    // initialize sum, maxSum and
    ll sum = 0, maxSum = INT_MIN, i;

    // Just some initial value to check for all negative values case
    *finish = -1;

    // local variable
    ll local_start = 0;

    for (i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;

    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;

    // Find the maximum element in array
    for (i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}


// The main function that finds maximum sum rectangle in M[][]
// use Kadane's algo in 1D, descripted avobe
ll MAT[101][101];
ll findMaxSum2D(ll ROW, ll COL) {
    // Variables to store the final output
    ll maxSum = INT_MIN;

    ll left, right, i;
    ll temp[ROW], sum, start, finish;

    // Set the left column
    for (left = 0; left < COL; ++left) {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));

        // Set the right column for the left column set by outer loop
        for (right = left; right < COL; ++right) {
            // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += MAT[i][right];

            // Find the maximum sum subarray in temp[]. The kadane()
            // function also sets values of start and finish.  So 'sum' is
            // sum of rectangle between (start, left) and (finish, right)
            //  which is the maximum sum with boundary columns strictly as
            //  left and right.
            sum = kadane(temp, &start, &finish, ROW);

            // Compare sum with maximum sum so far. If sum is more, then
            // update maxSum and other output values
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}


int main() {
    __FastIO;
    ll p, s, n, c1, c2, r1, r2, ans;

    cin >> p;
    while (p--) {
        cin >> s;
        cin >> n;
        //Fill(MAT, 1);
        REP(i, s) {
            REP(j, s) MAT[i][j] = 1;
            //NL;
        }
        REP(i, n) {
            cin >> r1 >> c1 >> r2 >> c2;
            FOR(j, r1, r2) FOR(k, c1, c2) MAT[j - 1][k - 1] = -INF;
        }
        //REP(i, s) {
        //    REP(j, s)cout << MAT[i][j] << '\t';
        //    NL;
        //}
        //CHK;
        ans = findMaxSum2D(s, s);
        cout << (ans == -INF? 0 : ans) << '\n';
    }
    return 0;
}

