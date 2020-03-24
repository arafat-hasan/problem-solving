/*
 * FILE: C.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 28-09-19 17:55:34 (+06)
 * LAST MODIFIED: 28-09-19 17:55:39 (+06)
 *
 * VERDICT:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 28-09-19     1.0         Deleted code is debugged code.
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
#include <tuple>
#include <iterator> // std::istream_iterator
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>
#include <unistd.h> // unsigned int sleep(unsigned int seconds);

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef long double         llf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vl;

#define _USE_MATH_DEFINES

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(a, val)    memset((a), (val), sizeof((a)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
#define nl              cerr << '\n'
#define sp              cerr << ' '
#define ckk             cerr << "###############\n"
#define debug1(x)       cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << '\n'
#else
#define nl
#define sp
#define ckk
#define debug1(x)
#define debug2(x, y)
#define debug3(x, y, z)
#endif

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

struct Rank{
    int id, solve, penalty, m, calcSolve, calcPenalty, rank;
    vi subs;
};

bool compare(Rank a, Rank b) {
    if(a.calcSolve > b.calcSolve) return true;
    if(a.calcSolve == b.calcSolve) {
        if(a.calcPenalty < b.calcPenalty)
            return true;
        if(a.calcPenalty == b.calcPenalty){
           return true; 
        }
        return false;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, n, cs = 0;
    cin >> k;
    while(k--){
        cin >> n;
        vector<Rank> v;
        vi rumor(n);
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            Rank tmp;
            cin >> tmp.id >> tmp.solve >> tmp.penalty >> tmp.m;
            int stupid;
            for(int j = 0; j < tmp.m; j++){
                cin >> stupid;
                tmp.subs.pb(stupid);
            }
            mp[tmp.id] = i;
            v.pb(tmp);

        }
        for (int j = 0; j < n; j++) {
            cin >> rumor[j];
        }

        bool ans = 1;
        int bS = INT_MAX, bP = INT_MAX;
        for (int j = 0; j < n; j++) {
            int rnk = rumor[j];
            int pos = mp[rnk];
            int solve = v[pos].solve;
            int penalty = v[pos].penalty;
            vi subsTmp = v[pos].subs;
            int crrS = solve, crrP = penalty;
            if(bS >= solve){
                for (int o = 0; o < (int) subsTmp.size(); o++) {
                    crrP += subsTmp[o];
                    crrS++;
                    if(crrS == bS and crrP < bP){
                        crrP -= subsTmp[o];
                        crrS--;
                        break;
                    }
                    if(crrS == bS and crrP == bP){
                        break;
                    }
                    if(crrS == bS and crrP > bP){
                        break;
                    }
                    if(crrS > bS) break;
                }
                v[pos].calcSolve = crrS;
                v[pos].calcPenalty = crrP;
                bS = crrS;
                bP = crrP;

            }else if(bS < solve){
                ans = 0;
                break;
            }

        }

        if(ans){
            sort(v.begin(), v.end(), compare);
            //for (int i = 0; i < n; i++) {
            //    debug3(v[i].id, v[i].calcSolve, v[i].calcPenalty);
            //}
            for (int j = 0; j < n; j++) {
                if(v[j].id != rumor[j]) {

                    ans = 0;
                    break;
                }
            }
        }
        cout << "Case " << ++cs << (ans? ": We respect our judges :)\n" : ": Say no to rumour >:\n");
    }
    return 0;
}


