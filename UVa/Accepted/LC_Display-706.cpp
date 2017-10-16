/*
 * FILE: LC Display-706.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 25-07-17 14:48:22 (BST)
 * LAST MODIFIED: 25-07-17 16:32:56 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 25-07-17     1.0         File Created, Accepted
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
    //__FastIO;
    int s, len;
    string n;
    while (cin >> s >> n) {
        if (n == "0" and s == 0) break;
        len = (int) n.size();
        for (int i = 1; i <= 2 * s + 3; i++) {
            for (int j = 0; j < len; j++) {
                if (i == 1 or i ==  s + 2 or i == 2 * s + 3) {
                    if (i == 1) {
                        if ( n[j] == '1' or n[j] == '4') {
                            cout << ' ';
                            for (int k = 0; k < s; k++) cout << ' ';
                            cout << ' ';
                        } else {
                            cout << ' ';
                            for (int k = 0; k < s; k++) cout << '-';
                            cout << ' ';
                        }
                    } else if (i == s + 2 ) {
                        if ( n[j] == '1' or n[j] == '7' or n[j] == '0') {
                            cout << ' ';
                            for (int k = 0; k < s; k++) cout << ' ';
                            cout << ' ';
                        } else {
                            cout << ' ';
                            for (int k = 0; k < s; k++) cout << '-';
                            cout << ' ';
                        }
                    } else {
                        if ( n[j] == '1' or n[j] == '4' or n[j] == '7') {
                            cout << ' ';
                            for (int k = 0; k < s; k++) cout << ' ';
                            cout << ' ';
                        } else {
                            cout << ' ';
                            for (int k = 0; k < s; k++) cout << '-';
                            cout << ' ';
                        }
                    }
                } else {
                    if (i < s + 2) {
                        if (n[j] == '1' or n[j] == '2' or n[j] == '3' or n[j] == '7') {
                            for (int k = 0; k < s + 1; k++) cout << ' ';
                            cout << '|';
                        } else if (n[j] == '5' or n[j] == '6') {
                            cout << '|';
                            for (int k = 0; k < s + 1; k++) cout << ' ';
                        } else {
                            cout << '|';
                            for (int k = 0; k < s; k++) cout << ' ';
                            cout <<  '|';
                        }
                    } else {
                        if (n[j] == '1' or n[j] == '3' or n[j] == '4' or n[j] == '5' or n[j] == '7'
                                or n[j] == '9') {
                            for (int k = 0; k < s + 1; k++) cout << ' ';
                            cout << '|';
                        } else if (n[j] == '2') {
                            cout << '|';
                            for (int k = 0; k < s + 1; k++) cout << ' ';
                        } else {
                            cout << '|';
                            for (int k = 0; k < s; k++) cout << ' ';
                            cout <<  '|';
                        }
                    }
                }
                if (j + 1 < len) cout << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
