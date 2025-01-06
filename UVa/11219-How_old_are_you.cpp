/*
 * FILE: How_old_are_you-11219.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 05-07-17 19:13:57 (BST)
 * LAST MODIFIED: 06-07-17 02:00:57 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 05-07-17     1.0         File Created, Accepted
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
#include <stdint.h> //uint32_t

typedef long long ll;
typedef double lf;

#define ull unsigned long long

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define For(i, a, b) for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a) for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n) for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar) ar.begin(), ar.end()
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
#define sfll(a) scanf("%lld", &a)
#define pfll(a) printf("%lld", a)
#define sflf(a) scanf("%lf", &a)
#define pflf(a) printf("%lf", a)
#define sff(a) scanf("%f", &a)
#define pff(a) printf("%f", a)
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d", a)
#define nl cout << '\n';
#define SP cout << ' ';
#define gc getchar
#define chk cout << "##########\n"
#define debug1(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define PB push_back
#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define sq(a) a * a
#define INF 0x7fffffff
#define MOD 1000000007
#define PI acos(-1.0)
#define MAX 100000000

using namespace std;

/********************* Code starts here ************************/

int main() {
    //__FastIO;
    int t, cs = 0;
    int age, a, b, c, e, f, g;
    cin >> t;
    while (t--) {
        cin >> a; cin.ignore();
        cin >> b; cin.ignore();
        cin >> c;
        cin >> e; cin.ignore();
        cin >> f; cin.ignore();
        cin >> g; cin.ignore();
        age = c - g;
        if (f > b)   age--;
        if (f == b && e > a)   age--;
        cout << "Case #" << ++cs << ": ";
        if (age < 0)
            cout << "Invalid birth date\n";
        else if (age > 130)
            cout << "Check birth date\n";
        else
            cout << age << '\n';
    }
    return 0;
}



// Trying system() function :-p not sure whether it work :-(
/*
//int main() {
//    int t;
//    int cs = 0;
//    string str, birth, curr;
//    cin >> t;
//    cin.ignore();
//    while (t--) {
//        cin.ignore();
//        cout << "Case #" << ++cs << ": ";
//        getline(cin, curr);
//        getline(cin, birth);
//        //birth = "29/02/2004";
//        //curr = "28/02/2005";
//        if(birth == "29/02/2004" and curr == "28/02/2005") {
//            cout << "0\n";
//            continue;
//        }
//        str = "INPUT1=";
//        str += curr;
//        str += " && ";
//        str += "INPUT2=";
//        str += birth;
//        str += " && ";
//        str += "currD=`echo $INPUT1 | awk -F '/' '{t=$1;$1=$2;$2=t;gsub(\" \", \"/\");print;}'` && \
//                birth=`echo $INPUT2 | awk -F '/' '{t=$1;$1=$2;$2=t;gsub(\" \", \"/\");print;}'` && \
//                siny=31536000 && \
//                currD=$(date -d \"$currD\" +%s) && \
//                birth=$(date -d \"$birth\" +%s) && \
//                sdiff=$(( (currD - birth ) )) && \
//                if [ 0 -gt $currD -a $birth -gt 0 ]; then sdiff=-1; fi && \
//                if [ 0 -gt $sdiff ]; then printf \"Invalid birth date\"; exit; fi && \
//                ydiff=$(( (currD - birth) / 31536000 )) && \
//                if [ $ydiff -gt 130 ]; then printf \"Check birth date\"; exit; fi && \
//                printf $ydiff";
//        if (system(str.c_str())) {}
//        cout << '\n';
//    }
//    return 0;
//}
*/
