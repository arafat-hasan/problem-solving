/*
 * FILE: Roman_Digititis-344.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 10-10-17 17:04:18 (+06)
 * LAST MODIFIED: 12-10-17 15:53:22 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 10-10-17     1.0         File Created, Accepted
 *
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

#define FileIn(file)    freopen("input.txt", "r", stdin)
#define FileOut(file)   freopen("output.txt", "w", stdout)
#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define sfll(a)         scanf("%lld", &a)
#define pfll(a)         printf("%lld", a)
#define sflf(a)         scanf("%lf", &a)
#define pflf(a)         printf("%lf", a)
#define sff(a)          scanf("%f", &a)
#define pff(a)          printf("%f", a)
#define sf(a)           scanf("%d", &a)
#define pf(a)           printf("%d", a)

#define nl              cout << '\n';
#define sp              cout << ' ';
#define gc              getchar
#define chk             cout << "##########\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define max(a, b)       (a < b ? b : a)
#define min(a, b)       (a > b ? b : a)
#define sq(a)           (a * a)

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAXN            32001
#define MAXS            100000000
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

struct foo {
    int I, V, X, L, C;
};

string to_roman(int value) {
    struct romandata_t {
        int value;
        char const *numeral;
    };
    static romandata_t const romandata[] = {
        1000, "M",
        900, "CM",
        500, "D",
        400, "CD",
        100, "C",
        90, "XC",
        50, "L",
        40, "XL",
        10, "X",
        9, "IX",
        5, "V",
        4, "IV",
        1, "I",
        0, NULL
    }; // end marker

    string result;
    for (romandata_t const *current = romandata; current->value > 0; ++current) {
        while (value >= current->value) {
            result += current->numeral;
            value  -= current->value;
        }
    }
    return result;
}

int main() {
    __FastIO;
    int n;
    vector<string> v(100);
    vector<foo> ans;
    foo fun;
    int ii, vv, xx, lll, cc;
    ii = vv = xx = lll = cc = 0;
    for (int i = 1; i < 101; i++) {
        v[i - 1] = to_roman(i);
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < (int) v[i].size(); j++) {
            if (v[i][j] == 'I') ii++;
            else if (v[i][j] == 'V') vv++;
            else if (v[i][j] == 'X') xx++;
            else if (v[i][j] == 'L') lll++;
            else if (v[i][j] == 'C') cc++;
        }
        debug3(i, v[i], ii);
        fun.I = ii; fun.V = vv; fun.X = xx; fun.L = lll; fun.C = cc;
        ans.pb(fun);
    }

    while (cin >> n and n) {
        cout << n << ": ";
        cout << ans[n - 1].I << " i, " << ans[n - 1].V << " v, " << ans[n - 1].X <<
             " x, "\
             << ans[n - 1].L << " l, " << ans[n - 1].C << " c\n";
    }
    return 0;
}

