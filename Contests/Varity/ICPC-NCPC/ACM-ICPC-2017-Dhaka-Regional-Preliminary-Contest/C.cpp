/*
 * FILE: C.cpp
 *
 * @author: MBSTU_TriO
 *
 * LINK:
 *
 * DATE CREATED: 23-09-17 16:20:39 (BDT)
 * LAST MODIFIED: 23-09-17 17:14:49 (BDT)
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
#define MAX             10000005

////////////////////////// START HERE //////////////////////////


int main() {
    __FastIO;
    int t, n, arr[10][10], cnt = 0, cs = 0;
    set<int> st;
    cin >> t;
    while (t--) {
        cin >> n;
        rep(i, n) rep(j, n) cin >> arr[i][j];
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // first in array, (i, j)
                //debug2(i, j);
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        // second point (k, l)
                        //debug3("   ", k, l);
                        if ((k - i + 1) * (l - j + 1) !=  10) continue;
                        st.clear();
                        for (int m = i; m <= k; m++) {
                            for (int o = j; o <= l; o++) {
                                st.insert(arr[o][m]);
                            }
                        }
                        if (st.size() == 10) cnt++;
                    }
                }
            }
        }
        cout << "Case " << ++cs << ": " << cnt << '\n';
    }

    return 0;
}

