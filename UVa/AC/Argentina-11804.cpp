/*
 * FILE: Argentina-11804.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 22-06-17 22:55:28 (BST)
 * LAST MODIFIED: 23-06-17 00:05:15 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 22-06-17     1.0         File Created, Accepted
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

#define For(i, a, b) for (int i=a; i<=b; i++)
#define Rof(i, b, a) for (int i=b; i>=a; i--)
#define Rep(i, n) for (int i=0; i<n; i++)
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

struct Player {
    string name;
    int attack_pw, defend_pw;
};

bool compare_player(Player a, Player b) {
    if (a.attack_pw != b.attack_pw)
        return a.attack_pw > b.attack_pw;
    if (a.defend_pw != b.defend_pw)
        return a.defend_pw < b.defend_pw;
    return a.name < b.name;
}

void struct_sort(Player a[], int n) {
    sort(a, a + n, compare_player);
}

int main() {
    __FastIO;
    int t, cs = 0;
    vector<string> v;
    Player argentina[10];
    cin >> t;
    while (t--) {
        Rep(i, 10)
        cin >> argentina[i].name >> argentina[i].attack_pw >> argentina[i].defend_pw;

        struct_sort(argentina, 10);

        cout << "Case " << ++cs << ":\n";

        Rep(i, 5) v.push_back(argentina[i].name);
        sort(v.begin(), v.end());
        cout << "(";
        cout << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ", " << v[4];
        cout  << ")\n";

        For(i, 5, 9) v.push_back(argentina[i].name);
        sort(v.begin() + 5, v.end());
        cout << "(";
        cout << v[5] << ", " << v[6] << ", " << v[7] << ", " << v[8] << ", " << v[9];
        cout << ")\n";

        v.clear();
    }
    return 0;
}

