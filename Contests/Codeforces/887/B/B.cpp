/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 03-11-17 22:17:28 (+06)
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 03-11-17     1.0         {{File Created}}
 *
 *
 *                 ██╗███████╗███╗   ██╗██╗███╗   ██╗
 *                 ██║██╔════╝████╗  ██║██║████╗  ██║
 *                 ██║█████╗  ██╔██╗ ██║██║██╔██╗ ██║
 *            ██   ██║██╔══╝  ██║╚██╗██║██║██║╚██╗██║
 *            ╚█████╔╝███████╗██║ ╚████║██║██║ ╚████║
 *             ╚════╝ ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝
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


int main() {
    __FastIO;
    int n, mat[3][6];
    cin >> n;
    set<int> ans;
    rep(i, n) {
        rep(j, 6)
        cin >> mat[i][j];
    }
    if (n == 1) {
        for (int i = 0; i < 6; i++) {
            ans.insert(mat[0][i]);
        }
    } else if (n == 2) {
        for (int i = 0; i < 6; i++) {
            ans.insert(mat[0][i]);
            for (int j = 0; j < 6; j++) {
                ans.insert(mat[1][j]);
                ans.insert(mat[0][i] * 10 + mat[1][j]);
                ans.insert(mat[0][i] + mat[1][j] * 10);
            }
        }
    } else {
        for (int i = 0; i < 6; i++) {
            ans.insert(mat[0][i]);
            for (int j = 0; j < 6; j++) {

                ans.insert(mat[1][j]);
                ans.insert(mat[0][i] * 10 + mat[1][j]);
                ans.insert(mat[0][i] + mat[1][j] * 10);
                for (int k = 0; k < 6; k++) {
                    ans.insert(mat[2][k]);

                    ans.insert(mat[1][j] * 10 + mat[2][k]);
                    ans.insert(mat[1][j] + mat[2][k] * 10);

                    ans.insert(mat[0][i] * 10 + mat[2][k]);
                    ans.insert(mat[0][i] + mat[2][k] * 10);

                    ans.insert(mat[0][i] * 100 + mat[1][j] * 10 + mat[2][k]);
                    ans.insert(mat[0][i]  + mat[1][j] * 10 + mat[2][k] * 100);
                    ans.insert(mat[0][i] * 10 + mat[1][j] * 100 + mat[2][k]);
                    ans.insert(mat[0][i] * 10 + mat[1][j] + mat[2][k] * 100);
                    ans.insert(mat[0][i] * 100 + mat[1][j] + mat[2][k] * 10);
                    ans.insert(mat[0][i] + mat[1][j] * 100 + mat[2][k] * 10);
                }
            }
        }
    }
    if (*ans.begin() == 0) ans.erase(ans.begin());
    if (*(ans.begin()) != 1) return !(cout << "0\n");
    set<int> ::iterator it;
    for (set<int> ::iterator i = ans.begin(); i != ans.end(); i++) {
        it = i;
        it++;
        if (it == ans.end()) return !(cout << *i << endl);
        if (*i + 1 != *it) {
            return !(cout << *i << endl);
        }
    }
    return 0;
}

