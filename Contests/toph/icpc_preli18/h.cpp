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
#include <unordered_set>
#include <queue>
#include <deque>
#include <vector>
#include <tuple>
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

#define _FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

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

int main() {
    _FastIO;
    string str;
    int t, cs = 0;
    cin >> t;

    while (t--) {
        cin >> str;
        int sz = (int) str.size();
        ll ans = 1;
        bool isW = false;
        //debug1 (str);

        for (int i = 0; i < sz; i++) {
            if (str[i] == 'W') {
                isW = true;
                int start = i;
                int cnt = 0;

                for (; i < sz; i++) {
                    if (str[i] != 'W') break;

                    cnt++;
                }

                int end = i - 1;
                //debug3 (cnt, start, end);
                ll com = 1;

                if (start == 0 or end == sz - 1) {
                    if (start == 0 and end == sz - 1) {
                        com = 3;

                        for (int j = 1; j < cnt; j++) {
                            com = (com * 2) % MOD;
                        }

                    } else {
                        for (int j = 0; j < cnt; j++) {
                            com = (com * 2) % MOD;
                        }
                    }

                } else {
                    int hor = 2;
                    int lob = 1;

                    for (int j = 1; j < cnt - 2; j++) {
                        lob = (hor - lob) % MOD;

                        if (lob < 0) lob += MOD;

                        hor = (hor * 2) % MOD;
                    }

                    //debug2 (lob, hor);
                    com = ((lob + hor) % MOD * 2) % MOD;

                    if (str[start - 1] == str[end + 1]) {
                        if (cnt <= 2) {
                            com = 2;
                        }

                    } else {
                        if (cnt == 1) com = 1;
                        else if (cnt == 2) com = 3;
                        else if (cnt & 1) com--;
                        else com++;
                    }
                }

                ans = (ans * com) % MOD;
            }
        }

        cout << "Case " << ++cs << ": ";
        cout << (isW ? ans : 0) << '\n';
    }

    return 0;
}
