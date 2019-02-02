/*
 * FILE: Common_characters_in_n_strings.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://www.geeksforgeeks.org/common-characters-n-strings
 *
 * DATE CREATED: 02-02-19 12:47:20 (+06)
 * LAST MODIFIED: 02-02-19 12:48:36 (+06)
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 02-02-19     1.0         Deleted code is debugged code.
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

const int MAX_CHAR = 26;

void commonCharacters (string str[], int n) {
    // primary array for common characters
    // we assume all characters are seen before.
    bool prim[MAX_CHAR];
    memset (prim, true, sizeof (prim));

    // for each string
    for (int i = 0; i < n; i++) {
        // secondary array for common characters
        // Initially marked false
        bool sec[MAX_CHAR] = { false };

        // for every character of ith string
        for (int j = 0; str[i][j]; j++) {
            // if character is present in all
            // strings before, mark it.
            if (prim[str[i][j] - 'a'])
                sec[str[i][j] - 'a'] = true;
        }

        // copy whole secondary array into primary
        memcpy (prim, sec, MAX_CHAR);
    }

    // displaying common characters
    for (int i = 0; i < 26; i++)
        if (prim[i])
            cout << (char) (i + 'a') << ' ';
}

// Driver's Code
int main() {
    ios_base::sync_with_stdio (false); cin.tie (0); cout.tie (0);
    string str[] = { "geeksforgeeks",
                     "gemkstones",
                     "acknowledges",
                     "aguelikes"
                   };
    int n = sizeof (str) / sizeof (str[0]);
    commonCharacters (str, n);
    return 0;
}
