/*
 * FILE: Numeral_Hieroglyphs-11787.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 26-07-17 22:06:21 (BST)
 * LAST MODIFIED: 27-07-17 16:08:58 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 26-07-17     1.0         File Created, Accepted
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


int main() {
    __FastIO;
    int n;
    string str;
    map<char, int> mp;
    mp['B'] = 1; mp['U'] = 10; mp['S'] = 100; mp['P'] = 1000; mp['F'] = 10000;
    mp['T'] = 100000; mp['M'] = 1000000;
    vector<char> order = {'B', 'U', 'S', 'P', 'F', 'T', 'M'};
    cin >> n;
    while (n--) {
        cin >> str;
        map<char, int> cnt;
        int len = (int) str.size();
        if ( len > 63) {
            cout << "error\n";
            continue;
        }

        bool flg = 1;
        for (int i = 0; i < len; i++) {
            cnt[str[i]]++;
            if (cnt[str[i]] >= 10) {
                cout << "error\n";
                flg = 0;
                break;
            }
        }
        if (!flg) continue;
        int fl = 0;
        if (find(all(order), str[0]) >= \
                find(all(order), str[(int) str.size() - 1])) fl = 1;
        else fl = -1;
        flg = 1;
        for (int i = 1; i < len; i++) {
            if (fl == 1) {
                if (find(all(order), str[i]) > find(all(order), str[i - 1])) {
                    cout << "error\n";
                    flg = 0;
                    break;
                }
            } else {
                if (find(all(order), str[i]) < find(all(order), str[i - 1])) {
                    cout << "error\n";
                    flg = 0;
                    break;
                }
            }
        }
        if (!flg) continue;
        map<char, int> freq;
        for (int i = 0; i < len; i++) {
            freq[str[i]]++;
        }
        int ans = 0;
        Forit(i, freq) {
            int tmp = i->second * mp[i->first];
            ans += tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}

