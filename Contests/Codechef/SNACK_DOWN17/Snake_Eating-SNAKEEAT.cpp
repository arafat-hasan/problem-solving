/*
 * FILE: Snake_Eating-SNAKEEAT.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 20-05-17 20:00:00 (+06)
 * LAST MODIFIED: 24-05-17 16:37:23 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 20-05-17     1.0         File Created
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

int arr[100005];

int up_bound( int low, int high, int key ) {

    int mid, ans = 0;

    do {
        mid = (low + high) / 2;
        if ( arr[mid] >= key ) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } while (low <= high);

    return ans;

}

int main() {

    __FastIO;
    int T, q, x, n, ans, point, suru, need, i, j;
    cin  >> T;
    while ( T-- ) {
        cin >> n >> q;
        for (i = 0; i < n; i++ ) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        //for (i = 0; i < n; i++ ) {
        //    cout << arr[i] << '\t' ;
        //}
        //NL;
        //for ( int i = 0; i < n; i++ ) {
        //    arr[i] += i;
        //    //cout << arr[i]  << '\t';
        //}
        //NL;NL;NL;
        for (i = 0; i < q; i++ ) {
            cin >> x;
            //if ( x <= arr[0] ) {
            //    cout << n << "\n";
            //    //DEBUG2(x, n);
            //} else {
            //    ans = up_bound(0, n - 1, x);
            //    //DEBUG2(ans, arr[ans]);
            //    if ( ans != 0 ) {
            //        if (arr[ans] == x && ans + 1 != n)
            //            //DEBUG2(x, n-ans-1);
            //            cout << n - ans - 1 << "\n";
            //        else
            //            cout << n - ans << "\n";
            //        //DEBUG2(x, n - ans);
            //    } else {
            //        cout  << ans << "\n";
            //        //DEBUG2(x, ans);
            //    }
            //}



            if ( x <= arr[0] ) {
                cout << n << "\n";
                //DEBUG2(x, n);
            } else {
                ans = up_bound(0, n - 1, x);
                //DEBUG2(ans, arr[ans]);
                if (ans == 0) ans = n;
                point = ans;
                ans = n - ans;
                //DEBUG3(x, ans, arr[ans]);
                //3 5   8   9   10  21
                //x: 10 ans: 4  arr[ans]: 10
                //x: 15 ans: 5  arr[ans]: 21
                //x: 12 ans: 5  arr[ans]: 21
                suru = 0;
                for (j = point - 1; j >= suru; j--) {
                    need = x - arr[j];
                    //DEBUG2(need, arr[j]);
                    if (suru + need > j) break;
                    ans++;
                    suru += need;

                }
                //DEBUG2(x, ans);
                cout << ans << '\n';
            }

        }
    }

    return 0;
}
