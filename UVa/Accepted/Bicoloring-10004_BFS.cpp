/********************************************************************
*   FILE NAME:  Bicoloring-10004_BFS.cpp
*
*   PURPOSE:    Solve of Uva problem.
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ----------------------------------------------------------------------
*   29 Oct 16      New         0.0         Completed, Not-Accepted, Without BFS
*   26 Jan 17       -          1.0          Complete, AC
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>

int bicolor(int n) ;

using namespace std;

vector<int> adj [300]; // for BFS & bfs_vis
int cost[10000]; // for BFS & bfs_vis

int main() {

    long long  n, l, a, b, i;


    while(cin >> n) {

        if(n==0)
            break;

        cin >> l;
       
	    for(i=0; i < l; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        if(bicolor(n))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");

        for(i = 0; i < n; i++)
            adj[i].clear();

    }

    return 0;
}



int bicolor(int n) {
	
    int i, cn, v, sz, color[n];
    for(i = 0; i < n; i++){
        cost[i]=INT_MAX;
        color[i] = 0;
        }

    queue<int> Q;
    Q.push(0);
    cost[0]=0;
    color[0] = 1;
    while(!Q.empty()) {
        cn = Q.front();
        Q.pop();
        sz = adj[cn].size();
        for(i=0; i<sz; i++) {
            v = adj[cn][i];
            
            if(color[v] == 0) color[v] = -color[cn];
            else if(color[v] != 0 && color[v] == color[cn]) return 0;
            
            if(cost[cn]+1<cost[v]) {
                Q.push(v);
                cost[v]= cost[cn]+1;
            }
        }
    }
    return 1;
}

