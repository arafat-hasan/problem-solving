/*
 * FILE: B.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 07-07-17 16:28:10 (BST)
 * LAST MODIFIED: 07-07-17 20:09:07 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 07-07-17     1.0         File Created
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
#include <stdint.h> //uint32_t

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define For(i, a, b) for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a) for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n) for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar) ar.begin(), ar.end()
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define nl cout << '\n';
#define SP cout << ' ';
#define gc getchar
#define chk cout << "##########\n"
#define debug1(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PB push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define sq(a) a * a
#define INF 10000000000000000
#define MOD 1000000007
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/

// Implementation of Kadane's algorithm for 1D array. The function
// returns the maximum sum and stores starting and ending indexes of the
// maximum sum subarray at addresses pointed by start and finish pointers
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


int main() {
    __FastIO;
    ll t, n, k, arr[5010], tmp, bar[5010],
    start, finish, maxsum, cs = 0, max, dump1, dump2;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        Rep(i, n) {
            cin >> tmp;
            arr[i] = tmp;
        }
    }
    cout << max << '\n';
//debug3(maxsum, start, finish);
    return 0;
}















//int main() {
//    __FastIO;
//    int t, n, k, arr[5010], tmp, bar[5010], start, finish, maxsum, cnt, min, index,
//        cs = 0, minindex;
//    cin >> t;
//    while (t--) {
//        cin >> n >> k;
//        Rep(i, n) {
//            cin >> tmp;
//            bar[i] = tmp;
//            arr[i] = (tmp < 0 ? 0 : tmp);
//        }
//        cout << "Case " << ++cs << ": ";
//        while (1) {
//            maxsum =  kadane(arr, &start, &finish, n);
//            cnt = 0;
//            For(i, start, finish) {
//                if (bar[i] < 0) cnt++;
//            }
//            if (cnt <= k) {
//                //fl = 1;
//                //debug2(start, finish);
//                cout << maxsum << '\n';
//                break;
//            }
//            min = INF; minindex = 0;
//            For(i, start, finish) {
//                if (bar[i] < 0) {
//                    index = i; cnt = 0;
//                    For(j, i, finish) {
//                        if (bar[j] < 0) {
//                            cnt++;
//                        } else break;
//                        i++;
//                    }
//                    //debug1(cnt);
//                    if (min > cnt) {
//                        min = cnt;
//                        minindex = index;
//                    }
//                }
//            }
//            //debug2(bar[minindex], min);
//            For(i, minindex, minindex + min-1)
//            arr[i] = -INF;
//        }
//        //debug3(maxsum, start, finish);
//    }
//    return 0;
//}

