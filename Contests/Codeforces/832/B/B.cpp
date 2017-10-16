/*
 * FILE: B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 24-07-17 21:07:21 (BST)
 * LAST MODIFIED: 24-07-17 23:43:25 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-07-17     1.0         File Created
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
    int n, match_len, len;
    string str, match;
    cin >> str;
    set<char> good(all(str));
    cin >> match;
    match_len = (int) match.size();
    cin >> n;
    while (n--) {
        cin >> str;
        len = (int) str.size();
        if (len + 1 == match_len or len == match_len) {
            if (len + 1 == match_len) {
                bool fl = 1;
                bool astr = 0;
                for (int i = 0, j = 0; j < match_len; i++, j++) {
                    if (i == len) {
                        if (match[len] != '*') {
                            cout << "NO\n";
                            fl = 0;
                        }
                    }
                    if (match[j] == '?') {
                        if (good.count(str[i]) == 0) {
                            cout << "NO\n";
                            fl = 0;
                            break;
                        }
                    } else if (match[j] == '*') {
                        i--;
                        astr = 1;
                    } else if (str[i] != match[j]) {
                        cout << "NO\n";
                        fl = 0;
                        break;
                    }
                }
                if (fl) {
                    if (astr) cout << "YES\n";
                    else cout << "NO\n";
                }
            } else {
                bool fl = 1;
                for (int i = 0; i < len; i++) {
                    if (match[i] == '?') {
                        if (good.count(str[i]) == 0) {
                            cout << "NO\n";
                            fl = 0;
                            break;
                        }
                    } else if (match[i] == '*') {
                        if (good.count(str[i]) != 0) {
                            cout << "NO\n";
                            fl = 0;
                            break;
                        }
                    } else if (match[i] != str[i]) {
                        cout << "NO\n";
                        fl = 0;
                        break;
                    }
                }
                if (fl) cout << "YES\n";
            }
        } else cout << "NO\n";
    }
    return 0;
}

