/*
 * FILE: Y3K_Problem-893.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 22-07-17 06:14:56 (BST)
 * LAST MODIFIED: 23-07-17 17:18:41 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 22-07-17     1.0         File Created, Accepted
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
typedef vector<pii>			vpii;
typedef vector<int>			vi;

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

bool isleapyear(long int year) {
    /*Is year divided by 4? After every 100 years a leap year is not
    counted and after every 400 years we count leap year*/
    if ((((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0))
        return true;
    else return false;
}

int main() {
    __FastIO;
    int n, d, m, y;
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(cin >> n >> d >> m >> y and n and m and y) {
        if(isleapyear(y)) month[1] = 29;
        else month[1] = 28;
        m -= 2;
        while(m >= 0) {
            n += month[m];
            m--;
        }
        m = 0;
        n += d;
        int reminder_day = n;
        int year_now = y;
        int year_day = 365 + isleapyear(year_now);
        while(reminder_day > year_day) {
            year_now++;
            reminder_day -= year_day;
            year_day = 365 + isleapyear(year_now);
        }
        if(isleapyear(year_now)) month[1] = 29;
        else month[1] = 28;
        int month_len = month[m];
        while(reminder_day > month_len) {
            m++;
            if(m > 11) {
                year_now++;
                m = 0;
            }
            reminder_day -= month_len;
            month_len = month[m];
        }
        cout << reminder_day << ' ' << m+1 << ' ' << year_now << '\n';
    }
    return 0;
}
