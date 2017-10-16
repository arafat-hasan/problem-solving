/*
 * FILE: Equation-727.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 12-05-17 14:05:23 (+06)
 * LAST MODIFIED: 19-05-17 15:07:10 (+06)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 12-05-17     1.0         File Created, Accepted
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
#include <vector>

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define ALL(ar) ar.begin(), ar.end()
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define NL cout << '\n';
#define SP cout << ' ';
#define CHK cout << "##########\n"
#define DEBUG1(x) cout << #x << ": " << x << endl
#define DEBUG2(x, y) cout << #x << ": " << x << "\t" << #y << ": " << y << endl
#define DEBUG3(x, y, z) cout << #x << ": " << x << "\t" << #y << ": " << y << "\t" << #z << ": " << z << endl

#define PB push_back
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
#define sq(a) a * a
#define INF 2147483646
#define MOD 1000000007
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/

vector<string> infix_to_postfix(deque<string> v) {

    vector<string> P;
    stack<string> Stk;
    v.push_front("(");
    v.push_back(")");

    for (int i = 0 ; i < (int)v.size() ; i++) {
        //DEBUG1(v[i]);
        string tmp = v[i];
        /// Case 1 : number
        if (tmp[0] >= '0' && tmp[0] <= '9' ) {
            P.push_back(tmp);
        }
        /// Operator
        else if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/") {
            if (tmp == "+" || tmp == "-"   ) {
                while ( !Stk.empty() &&  ( Stk.top() == "+" || Stk.top() == "-"
                                           || Stk.top() == "*" || Stk.top() == "/" )  ) {
                    P.push_back(Stk.top() );
                    Stk.pop();
                }
            } else if (tmp == "*" || tmp == "/" ) {
                while ( !Stk.empty() &&  ( Stk.top() == "*" || Stk.top() == "/" )  ) {
                    P.push_back(Stk.top() );
                    Stk.pop();
                }
            }
            Stk.push(tmp);
        } else {
            /// Opening
            if (tmp == "(") Stk.push(tmp);
            else { /// )
                while (Stk.top() != "(") {
                    P.push_back(Stk.top() );
                    Stk.pop();
                }
                if (!Stk.empty()) Stk.pop();
            }
        }
        /// Par
    }

    return P;
}

int main() {

    int T;
    string str;
    deque<string> v;
    vector<string> P;

    cin >> T;
    cin.ignore();
    cin.ignore();
    while (T--) {
        while (getline(cin, str) && (str != "\n" && str != ""))
            v.push_back(str);
        P = infix_to_postfix(v);
        for (int i = 0; i < (int)P.size(); i++) {
            cout << P[i];
        }
        cout << '\n';
        if (T) cout << '\n';
        v.clear();
        P.clear();
    }
    return 0;
}

