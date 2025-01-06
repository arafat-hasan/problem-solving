/*
 * FILE: Spreading_the_News-924.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/9/924.pdf
 *
 * Description: Graph, BFS, DFS
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    17 Apr 2017    New             1.0        AC, BFS
 *    18 Apr 2017    New             1.1        AC, DFS
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


/**********************With BFS*************************/
int adj[2501][16], cost[2501], level[2501], E, max_boom, boom_lv;

void bfs(int src) {
    int v, cn;
    REP(i, E) {
        cost[i] = INF;
        level[i] = 0;
    }
    queue<int> Q;
    Q.push(src);
    cost[src] = 0;
    level[cost[src]]  = 1;
    max_boom = -1;
    while (!Q.empty()) {
        cn = Q.front();
        Q.pop();
        FOR(i, 1, adj[cn][0]) {
            v = adj[cn][i];
            if (cost[v] > cost[cn] + 1) {
                cost[v] = cost[cn] + 1;
                level[cost[v]]++;
                if (max_boom < level[cost[v]]) {
                    max_boom = level[cost[v]];
                    boom_lv = cost[v];
                }
                Q.push(v);
            }
        }
    }
}

int main() {

    std::ios::sync_with_stdio(false);
    int T, src;
    cin >> E;
    REP(i, E) {
        cin >> adj[i][0];
        FOR(j, 1, adj[i][0]) {
            cin >> adj[i][j];
        }
    }
    cin >> T;
    REP(i, T) {
        cin >> src;
        bfs(src);
        max_boom == -1 ? cout << "0\n" : cout << max_boom << ' ' << boom_lv << '\n';
    }

    return 0;
}

/***************************End BFS Solve*****************************/




/***************************DFS Solve********************************/
// int adj[2501][16], cost[2501], level[2501], E, max_boom, boom_lv;
// 
// void dfs(int src) {
//     FOR(i, 1, adj[src][0]) {
//         if (cost[adj[src][i]] > cost[src]  + 1) {
//             if (cost[adj[src][i]] != INF) level[cost[adj[src][i]]]--;
//             cost[adj[src][i]] = cost[src] + 1;
//             level[cost[adj[src][i]]]++;
//             dfs(adj[src][i]);
//         }
//     }
// }
// 
// int main() {
// 
//     std::ios::sync_with_stdio(false);
//     int T, src;
//     cin >> E;
//     REP(i, E) {
//         cin >> adj[i][0];
//         FOR(j, 1, adj[i][0]) {
//             cin >> adj[i][j];
//         }
//     }
//     cin >> T;
//     REP(i, T) {
//         cin >> src;
//         REP(j, E) {
//             cost[j] = INF;
//             level[j] = 0;
//         }
//         max_boom = -1;
//         cost[src] = 0;
//         //level[cost[src]]++;
//         dfs(src);
//         REP(k, E) {
//             if (max_boom < level[k]) {
//                 max_boom = level[k];
//                 boom_lv = k;
//             }
//         }
//         max_boom == 0 && boom_lv == 0 ? cout << "0\n" : cout << max_boom << ' ' << boom_lv << '\n';
//     }
// 
//     return 0;
// }

/**********************End DFS Solve**************************************/
