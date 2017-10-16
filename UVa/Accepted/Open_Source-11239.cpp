/*
 * FILE: Open_Source-11239.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-07-17 03:50:34 (+06)
 * LAST MODIFIED: 24-07-17 05:52:56 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-07-17     1.0         File Created, Accepted
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

/////////////////////////////////////////////////////////////////////////////

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

#define For(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof a)

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
#define EPS             1e-10
#define MAX             10000005

////////////////////////// START HERE //////////////////////////

struct foo {
    string name;
    int cnt;
};

bool compair(foo a, foo b) {
    if (a.cnt > b.cnt) return true;
    if (a.cnt == b.cnt) {
        if (a.name > b.name) return false;
        return true;
    }
    return false;
}

int main() {
    __FastIO;
    string str;
    map<string, int> project;
    map<string, pair<string, int> > id;
    getline(cin, str);
    while (1) {
        if (str[0] == '1') {
            vector<foo> ans((int) project.size(), foo());
            int j = 0;
            Forit(i, project) {
                ans[j].cnt = i->second;
                ans[j].name = i->first;
                j++;
            }
            sort(all(ans), compair);
            Forit(i, ans) cout << i->name << ' ' << i->cnt << '\n';

            project.clear();
            id.clear();
            getline(cin, str);
            continue;
        }
        if (str[0] == '0') {
            vector<foo> ans((int) project.size(), foo());
            int j = 0;
            Forit(i, project) {
                ans[j].cnt = i->second;
                ans[j].name = i->first;
                j++;
            }
            sort(all(ans), compair);
            Forit(i, ans) cout << i->name << ' ' << i->cnt << '\n';
            break;
        }

        if (str[0] >= 'A' and str[0] <= 'Z') {
            string project_now = str;
            set<string> st;
            while (getline(cin, str)) {
                if (!(str[0] >= 'a' and str[0] <= 'z')) {
                    break;
                }
                st.insert(str);
            }
            int cnt = 0;
            Forit(i, st) {
                if (id[*i].second == 0) {
                    cnt++;
                    id[*i].second++;
                    id[*i].first = project_now;
                } else {
                    if (id[*i].second == 1) {
                        project[id[*i].first]--;
                        id[*i].second++;
                    }
                }
            }
            project[project_now] = cnt;
        }
    }
    return 0;
}
