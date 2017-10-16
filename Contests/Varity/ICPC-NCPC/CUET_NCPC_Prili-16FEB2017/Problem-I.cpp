/*
 * FILE: Problem-I.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstdio>

#define FileIn(file) freopen(file"input.txt", "r", stdin)
#define FileOut(file) freopen(file"output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define MAX 1000000

typedef long long ll;

ll DFS(ll start,ll goal);

typedef long long ll;
using namespace std;

vector<int> adj [300];
vector<int>v [100];
bool visited[MAX];
long long c = 0;

int main() {

    int t, c = 0, city, edge, i, a, b, count;
    scanf("%d", &t);
    while(c++ <  t) {
        scanf("%d %d", &city, &edge);

        for(i=0; i < edge; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
        }


	
		count = 0;
        for(i = 1; i <= city; i++) {
            if(adj[i].empty() == 1){
				printf("##%d\n", i);
                count++;
			}
        }
        
        printf("%d", count);

    }
    return 0;
}





/**DFS */
//vector <int> v[100];
//bool visited[MAX];
//ll c = 0;
ll DFS(ll start,ll goal){
    if(c) return 1;
    if(start == goal) c = 1;
    cout<<start<<endl;
    visited[start] = true;
    ll sz = v[start].size();
    for(ll i=0; i<sz; i++) {
        ll adj_node = v[start][i];
        if(!visited[adj_node]){
            DFS(adj_node,goal);
        }
    }
    return c;
}


