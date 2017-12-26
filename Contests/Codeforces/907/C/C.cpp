/*
 * FILE: C.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-12-17 21:51:24 (+06)
 * LAST MODIFIED: 24-12-17 16:20:26 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-12-17     1.0         {{File Created}}
 *
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
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
typedef long double         llf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vl;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = a; i <= b; i++)
#define rof(i, b, a)    for (__typeof (a) i = b; i >= a; i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < n; i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "###############\n"
#define pb              push_back
#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //10e7

////////////////////////// START HERE //////////////////////////

int main() {
    __FastIO;
    int n;
    cin >> n;
    char ch;
    set<char> ans, nope;
    string str;
    int need  = 0, he_need = 0;
    bool first_time = true, got_ans = false;

    for (int i = 0; i < n; i++) {
        cin >> ch;
        //ckk;
        //debug1 (i);

        if (ch == '.') {
            cin >> str;

            for (int j = 0; j < (int) str.size() ; j++) {
                nope.insert (str[j]);
            }

            forit (j, nope) {
                if (ans.count (*j) != 0) {
                    if ( (int) ans.size() > 0)
                        ans.erase (*j);

                    if ( (int) ans.size() == 1 and got_ans == false) {
                        need = he_need;
                        got_ans = true;
                    }
                }
            }
            //debug1 (nope.size() );
            //forit (k, nope) cout << *k << ' ';
            //nl;
            //debug1 (ans.size() );
            //forit (k, ans) cout << *k << ' ';
            //nl;
            //throw 1;
        } else if (ch == '!') {
            he_need++;
            //cout << "asdf\n";
            cin >> str;
            set<char> st;

            if (first_time == true) {
                for (int j = 0; j < (int) str.size() ; j++) {
                    ans.insert (str[j]);
                }
            }

            for (int j = 0; j < (int) str.size() ; j++) {
                st.insert (str[j]);
            }

            forit (j, ans) {
                if (st.count (*j) == 0) {
                    if ( (int) ans.size() > 0)
                        ans.erase (*j);

                    if ( (int) ans.size() == 1 and got_ans == false) {
                        need = he_need;
                        got_ans = true;
                    }
                }
            }
            //debug1 (ans.size() );
            //forit (k, ans) cout << *k << ' ';
            //nl;
            first_time = false;
        } else if (ch == '?') {
            cin >> str;

            if (i != n - 1) {
                he_need++;

                if ( (int) ans.size() > 0)
                    ans.erase (str[0]);

                if ( (int) ans.size() == 1 and got_ans == false) {
                    need = he_need;
                    got_ans = true;
                }
            }

            //throw 3;
        } else cin >> str;

        //debug2 (ch, str);
        //debug2(he_need, need);
    }

    need = need == 0 ? he_need : need;
    //debug2 (need, he_need);
    cout << he_need - need << endl;
    return 0;
}

