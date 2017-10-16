/*
 * FILE: Number_Maze-929.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06-07-17 12:50:35 (BST)
 * LAST MODIFIED: 06-07-17 12:54:46 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 06-07-17     1.0         File Created
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

#define max(a, b) (a < b ? b : a)
#define min(a, b) (a > b ? b : a)
#define sq(a) a * a
#define PI acos(-1.0)

//**************** Bit Mask ***************
#define bit(n) (1 << (n)) //2^n
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << (i)))? 1 : 0)
#define bit_on(n, i) n = (n | (1 << (i))) //set ith bit ON of the integer n
#define bit_off(n, i) n = (n & ~(1 << (i))) //set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) n = (n ^ ( 1 << (i)))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) n = (n ^ ((-(x) ^ n) & (1 << (i))))

#define PB push_back
#define INF 0x7fffffff
#define MOD 1000000007
#define MAXN 32001
#define MAXS 100000000
#define MAX 10000005

using namespace std;


/********************* Code starts here ************************/


void bfs_visited(int s, int n) {

    int u, v, i, m;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        cost[i] = -1;
    }

    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    cost[s] = 0;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        m = (int) adj[u].size();

        for (i = 0; i < m; i++) {
            if (visited[adj[u][i]] == 0) {
                v = adj[u][i];
                visited[v] = 1;
                Q.push(v);
                cost[v] = cost[u] + 1;
            }
        }
    }
}

vector<int> adj [100]; // for BFS & bfs_vis
int cost[100]; // for BFS & bfs_vis
int visited [100]; //for bfs_vis

int bfs(int s, int n) {
    int i, cn, v, sz;
    for (i = 0; i < n; i++)
        cost[i] = INT_MAX;

    queue<int> Q;
    Q.push(s);
    cost[s] = 0;
    while (!Q.empty()) {
        cn = Q.front();
        Q.pop();
        sz = (int) adj[cn].size();
        for (i = 0; i < sz; i++) {
            v = adj[cn][i];
            if (cost[cn] + 1 < cost[v]) {
                Q.push(v);
                cost[v] = cost[cn] + 1;
            }
        }
    }

    return 0;
}


int main() {
    __FastIO;
    int t, n, m;
    return 0;
}

