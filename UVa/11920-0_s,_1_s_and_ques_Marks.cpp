/*
 * FILE: 0_s,_1_s_and_*_Marks-11920.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 16-07-17 17:42:12 (BST)
 * LAST MODIFIED: 17-07-17 04:26:47 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 16-07-17     1.0         File Created, Accepted
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
    int t, cs = 0, group, max;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        int len  = (int) str.size();
        max = 1;
        Rep(i, len) {
            group = 0;
            For(j, i, len - 1) {
                if (str[i] != str[j] or str[j] == '?') break;
                group++;
            }
            if (max < group) max = group;
        }

        if (str[0] == '?') {
            Rep(i, len) {
                if (str[i] != '?') {
                    if (i % 2) str[0] = str[i] == '1' ? '0' : '1';
                    else str[0] = str[i];
                    break;
                }
            }
            if (str[0] == '?') str[0] = '1';
        }

        Rep(i, len) {
            if (str[i] == '?') {
                int with1 = 0, with0 = 0, start;
                char ch = '0';
                Rep(j, 2) {
                    ch = (char) (ch + j);
                    str[i] = ch;
                    if (str[i - 1] == str[i] and str[i] == str[i + 1]) {
                        start = 0;
                        for (int k = i - 1; k >= 0; k--) {
                            if (str[k] != str[i]) {
                                start = k + 1;
                                break;
                            }
                        }
                        int tmp = len - start;
                        for (int k = start; k < len; k++) {
                            if (str[k] != str[i]) {
                                tmp = k - start;
                                break;
                            }
                        }
                        if (ch == '0') with0 = tmp;
                        else with1 = tmp;
                    } else if (str[i] == str[i - 1]) {
                        if (ch == '0') with0 = i + 1;
                        else with1 = i + 1;
                        for (int k = i; k >= 0; k--) {
                            if (str[k] != str[i]) {
                                if (ch == '0') with0 = i - k;
                                else with1 = i - k;
                                break;
                            }
                        }
                    } else {
                        if (ch == '0') with0 = len - i;
                        else with1 = len - i;
                        for (int k = i; k < len; k++) {
                            if (str[k] != str[i]) {
                                if (ch == '0') with0 = k - i;
                                else with1 = k - i;
                                break;
                            }
                        }
                    }
                }
                if (with0 > with1) {
                    if (max < with1) max = with1;
                    str[i] = '1';
                } else if (with0 < with1) {
                    if (max < with0) max = with0;
                    str[i] = '0';
                } else {
                    char chtmp = '1';
                    for (int k = i + 1; k < len; k++) if (str[k] == '?') {
                            chtmp = str[k + 1];
                            break;
                        }
                    if (max < with1) max = with1;
                    str[i] = chtmp;
                }
            }
        }
        cout << "Case " << ++cs << ": " << max << '\n';
    }
    return 0;
}

