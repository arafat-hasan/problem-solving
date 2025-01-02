/*
 * FILE: 47B.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 28-07-17 15:38:41 (BST)
 * LAST MODIFIED: 29-07-17 15:50:31 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 28-07-17     1.0         File Created
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
    string s1, s2, s3;

    getline(cin, s1);
    if (s1[1] == '>') reverse(all(s1));
    s1.erase(s1.begin() + 1);

    getline(cin, s2);
    if (s2[1] == '>') reverse(all(s2));
    s2.erase(s2.begin() + 1);

    getline(cin, s3);
    if (s3[1] == '>') reverse(all(s3));
    s3.erase(s3.begin() + 1);

    if (s1[0] == s2[1]) {
        s2.pb(s1[1]);
        if (s2[2] == s3[1]) cout << s2 << '\n';
        else cout << "Impossible\n";
    } else if (s1[0] == s3[1]) {
        s3.pb(s1[1]);
        if (s3[2] == s2[1]) cout << s3 << '\n';
        else cout << "Impossible\n";
    } else if (s2[0] == s1[1]) {
        s1.pb(s2[1]);
        if (s1[2] == s3[1]) cout << s1 << '\n';
        else cout << "Impossible\n";
    } else if (s2[0] == s3[1]) {
        s3.pb(s2[1]);
        if (s3[2] == s1[1]) cout << s3 << '\n';
        else cout << "Impossible\n";
    } else if (s3[0] == s1[1]) {
        s1.pb(s3[1]);
        if (s1[2] == s2[1]) cout << s1 << '\n';
        else cout << "Impossible\n";
    } else if (s3[0] == s2[1]) {
        s2.pb(s3[1]);
        if (s2[2] == s1[1])  cout << s2 << '\n';
        else cout << "Impossible\n";
    }

    return 0;
}

