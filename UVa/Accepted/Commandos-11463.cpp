/*
 * FILE: Commandos-11463.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: http://uva.onlinejudge.org/external/114/11463.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    05 Mar 2017    New             1.0        AC
 *
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

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back


#define nl cout << endl
#define chk cout << "##########" << endl
#define MAX 100

typedef long long ll;
using namespace std;


vector<int> adj [MAX]; // for BFS & bfs_vis
int cost[MAX], max_bld; // for BFS & bfs_vis

int bfs_des(int s, int des, int n) {
    int i, cn, v, sz;
    for(i = 0; i < n; i++)
        cost[i] = INT_MAX;

    queue<int> Q;
    Q.push(s);
    cost[s] = 0;
    while(!Q.empty()) {
        cn = Q.front();
        Q.pop();
        sz = adj[cn].size();
        for(i = 0; i < sz; i++) {
            v = adj[cn][i];
            if(cost[cn] + 1 < cost[v]) {
                Q.push(v);
                cost[v] = cost[cn] + 1;
                if(v == des) return cost[v];
            }
        }
    }

    return 0;
}


int main() {

    std::ios::sync_with_stdio(false);
    int T, n, r, cs = 0, s, d, src, des, max, tmp;
    cin >> T;
    while(cs++ < T){
        cin >> n >> r;
        REP(i, r){
            cin >> s >> d;
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        cin >> src >> des ;
        max = -1;
        REP(i, n){
            tmp = bfs_des(src, i, n) + bfs_des(i, des, n);
            if(max < tmp) max = tmp;
        }
        cout << "Case " << cs << ": " << max << "\n" ;

        REP(i, n) adj[i].clear();

    }
    return 0;

}



