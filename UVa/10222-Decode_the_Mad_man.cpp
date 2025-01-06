/*
 * FILE: Decode_the_Mad_man-10222.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 05-10-17 17:20:01 (+06)
 * LAST MODIFIED: 05-10-17 17:47:42 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 05-10-17     1.0         File Created, Accepted
 *
 *
 *
 *                 ██╗███████╗███╗   ██╗██╗███╗   ██╗
 *                 ██║██╔════╝████╗  ██║██║████╗  ██║
 *                 ██║█████╗  ██╔██╗ ██║██║██╔██╗ ██║
 *            ██   ██║██╔══╝  ██║╚██╗██║██║██║╚██╗██║
 *            ╚█████╔╝███████╗██║ ╚████║██║██║ ╚████║
 *             ╚════╝ ╚══════╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═══╝
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
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)    for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset(ar, val, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

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
#define EPS             1e-7
#define MAX             10000005

////////////////////////// START HERE //////////////////////////


int main() {
    __FastIO;
    map<char, char> mp;

    mp['e'] = 'q';
    mp['r'] = 'w';
    mp['t'] = 'e';
    mp['y'] = 'r';
    mp['u'] = 't';
    mp['i'] = 'y';
    mp['o'] = 'u';
    mp['p'] = 'i';
    mp['['] = 'o';
    mp[']'] = 'p';

    mp['d'] = 'a';
    mp['f'] = 's';
    mp['g'] = 'd';
    mp['h'] = 'f';
    mp['j'] = 'g';
    mp['k'] = 'h';
    mp['l'] = 'j';
    mp[';'] = 'k';
    mp['\''] = 'l';

    mp['c'] = 'z';
    mp['v'] = 'x';
    mp['b'] = 'c';
    mp['n'] = 'v';
    mp['m'] = 'b';
    mp[','] = 'n';
    mp['.'] = 'm';

    string str;
    size_t sz;
    while (getline(cin, str)) {
        sz = str.size();
        rep(i, sz) {
            if (mp.count(str[i])) {
                cout << mp[str[i]];
            } else if (isalpha(str[i])) {
                str[i] = (char) tolower(str[i]);
                cout << mp[str[i]];
            } else cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}

