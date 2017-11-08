/*
 * FILE: Walking_Robots.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://www.hackerrank.com/contests/101hack48/challenges/walking-robots
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 */


/*
    ___          ___           ___                       ___
   /  /\        /  /\         /__/\        ___          /__/\
  /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
 /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
 \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
    \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
     \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
     /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
    /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
    \__\/      \  \::/       \  \:\         \__\/      \  \:\
                \__\/         \__\/                     \__\/
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <set>

typedef long long ll;
typedef double lf;

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646


#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define ln cout << '\n';
#define sp cout << ' ';
#define chk cout << "##########\n"

using namespace std;


int howManyCollisions(string s) {
    int len = s.length(), col = 0, i;
    bool fl;
    if (s[0] == 'l') s[0] = 'd';
    if (s[len - 1] == 'r') s[len - 1] = 'd';
    for (int j = 0; j < len; j++) {
        fl = 0;
        for (i = 0; i < len; i++) {
            if(s[i] != 'd') fl = 1;
            if (s[i] == 'd') {
                if (s[i + 1] == 'l') {
                    col++;
                    s[i + 1] = 'd';
                }
                //break;
            }
            else if (s[i] == 'r') {
                if (s[i + 1] == 'l') {
                    col += 2;
                    s[i + 1] = s[i] = 'd';
                }
                else if (s[i + 1] == 'd') {
                    col++;
                    s[i] = 'd';
                }
                //break;
            }
        }
        if(fl == 0) break;
    }
    return col;
}

int main() {
    int q;
    cin >> q;
    for (int a0 = 0; a0 < q; a0++) {
        string s;
        cin >> s;
        // Returns the number of times moving robots collide.
        int result = howManyCollisions(s);
        cout << result << endl;
    }
    return 0;
}
