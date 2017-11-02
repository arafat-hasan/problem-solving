/*
 * FILE: /media/Softwares/Programming/ACM/Contests/Codechef/LTIME53/MAXNUM3.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 28-10-17 20:38:16 (+06)
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 28-10-17     1.0         {{File Created}}
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
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

int stoi_s(string str) {
    int sz = (int)str.size(), n  = str[0];
    for (int i = 1; i < sz; i++) {
        n = (n * 10) + str[i] - 48;
    }
    return n;
}

int main() {
    __FastIO;
    int t;
    string str, strtmp;
    //debug1(stoi_s("1234999"));
    //return 0;
    cin >> t;
    while (t--) {
        cin >> str;
        vi v;
        map<int, string> mp;
        for (int i = 0; i < 10; i++) {
            int sz = (int) str.size();
            for (int j = sz - 1; j >= 0; j--) {
                if (str[j] == i + 48) {
                    strtmp = str;
                    strtmp.erase(strtmp.begin() + j);
                    int tmp = stoi_s(strtmp);
                    //int tmp;
                    //istringstream ss(strtmp);
                    //ss >> tmp;
                    if (tmp % 6 == 0) {
                        v.pb(tmp);
                        mp[tmp] = strtmp;
                        break;
                    }
                }
            }
        }
        int max = -INF;
        forit(i, v) {
            if (*i > max) max = *i;
        }
        cout << ((int) v.size() == 0 ? "-1" : mp[max]) << '\n';
    }
    return 0;
}

