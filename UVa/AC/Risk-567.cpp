/********************************************************************
*   FILE NAME:  Risk-567.cpp
*
*   LINK: https://uva.onlinejudge.org/external/5/567.pdf
*
*   @author: Md. Arafat Hasan Jenin
*   EMAIL:  OpenDoor.Arafat@gmail.com
*
*   DEVELOPMENT HISTORY:
*       Date        Change      Version     Description
* ---------------------------------------------------------------------
*   18 Feb 17       -          1.0          BFS, AC
*   16 Apr 17       New        1.1          DFS
**********************************************************************/

#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <iomanip>
#include <iostream>

#define INF 2147483646

using namespace std;

/************************************With BFS*********************************/

int BFS(int src, int dst);

vector<int> adj[20];
int cost[20];

int main() {
    int i, src, dst, X, N, a, j, Case = 0;

    while(1){

        for(i = 0; i < 19; i++){
            if(scanf("%d", &X) != 1) return 0;
            for(j = 0; j < X; j++){
                scanf("%d", &a);
                adj[i].push_back(a-1);
                adj[a-1].push_back(i);
            }
        }


        scanf("%d", &N);
        printf("Test Set #%d\n",++Case);
        for(i = 0; i < N; i++){
            scanf("%d %d", &src, &dst);
            printf("%2d to %2d: %d\n", src, dst, BFS(src-1, dst-1));
       }
        printf("\n");

        for(i = 0; i < 20; i++) adj[i].clear();
    }

    return 0;

}


int BFS(int src, int dst){

    int cn, sz, i;

    for(i = 0; i < 20; i++)
        cost[i] = INT_MAX;

    queue<int> Q;
    Q.push(src);
    cost[src] = 0;

    while(!Q.empty()){
    cn = Q.front();
    Q.pop();
    sz = adj[cn].size();
        for(i = 0; i < sz; i++){
            if(cost[adj[cn][i]] > cost[cn] + 1){
                Q.push(adj[cn][i]);
                cost[adj[cn][i]] = cost[cn] + 1;
                if(adj[cn][i] == dst) return cost[dst];
            }
        }
    }

    return 0;
}


/********************************END of BFS Solve********************************/




/*****************************Start of DFS Solve*********************************/

// int visited[20], cost[20];
// vector<int> adj[20];
// 
// void dfs(int src) {
//     int i, v, sz;
//     visited[src] = 1;   ///Gray = visiting = 1, black = visited = 2;
//     sz = adj[src].size();
//     for (i = 0; i < sz; i++) {
//         v = adj[src][i];
//         if (cost[v] > cost[src] + 1) {
//             cost[v] = cost[src] + 1;
//             dfs(v);
//         }
//     }
// }
// 
// int main() {
//     int i, src, dst, X, N, a, j, Case = 0;
//     while (1) {
//         for (i = 0; i < 19; i++) {
//             if (scanf("%d", &X) != 1) return 0;
//             for (j = 0; j < X; j++) {
//                 scanf("%d", &a);
//                 adj[i].push_back(a - 1);
//                 adj[a - 1].push_back(i);
//             }
//         }
// 
//         scanf("%d", &N);
//         printf("Test Set #%d\n", ++Case);
//         for (i = 0; i < N; i++) {
//             for (j = 0; j < 20; j++) {
//                 cost[j] = INF;
//             }
//             scanf("%d %d", &src, &dst);
//             cost[src - 1] = 0;
//             dfs(src - 1);
//             printf("%2d to %2d: %d\n", src, dst, cost[dst - 1]);
//         }
//         printf("\n");
// 
//         for (i = 0; i < 20; i++) {
//             adj[i].clear();
//         }
//     }
//     return 0;
// }

/****************************END of DFS Solve********************************************/
