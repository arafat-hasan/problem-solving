/*
 * FILE: Bombs_NO_they_are_Mines-10653.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/106/10653.pdf
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    30 Jan 2017    New             1.0        Completed, AC
 *
 *
 */


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <utility>
#include <cstring>

typedef long long ll;
using namespace std;

int bfs_visited(int sx, int sy, int n, int m, int dx, int dy);
int valid(int tx, int ty);
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int cost[1010][1010], land[1010][1010]; // for BFS & bfs_vis
int visited [1010][1010]; //for bfs_vis
int r, c, S[2], D[2], row_with_bomb, col_w_b, row_num_w_b, col_num_w_b;

int main() {

    int i, j;
    pair <int, int> source;
    while(cin >> r >> c, r || c) {
        memset(land, 0, sizeof(land));
        cin >> row_with_bomb;
        for(i = 0; i < row_with_bomb; i++) {
            cin >> row_num_w_b;
            cin >> col_w_b;
            for(j = 0; j < col_w_b; j++) {
                cin >> col_num_w_b;
                land[row_num_w_b][col_num_w_b] = -1;
            }
        }

        cin >> S[0] >> S[1] >> D[0] >> D[1];
        printf("%i\n", bfs_visited(S[0], S[1], r, c, D[0], D[1]));

    }

    return 0;
}


int bfs_visited(int sx, int sy, int n, int m, int dx, int dy) {

    if(sx == dx && sy == dy) return 0;

    int i, j, tx, ty;

    for(i=0; i < r; i++) {
        for(j = 0; j < c; j++)
            visited[i][j] = 0;
        cost[i][j] = -1;
    }

    queue<pair<int, int>> Q;
    Q.push(pair<int, int>(sx, sy));
    visited[sx][sy] = 1;
    cost[sx][sy] = 0;

    while(!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();
        for(i = 0; i < 4; i++) {
            tx=u.first+fx[i];
            ty=u.second+fy[i];
            if(valid(tx, ty)) {
                visited[tx][ty] = 1;
                Q.push(pair<int, int>(tx, ty));
                cost[tx][ty] = cost[u.first][u.second]+1;
                if(tx == dx && ty == dy) return cost[tx][ty];
            }
        }
    }
    return 0;
}


int valid(int tx, int ty) {
    if(tx>=0 && tx<r && ty>=0 && ty<c && land[tx][ty]!=-1 && visited[tx][ty]==0) return 1;
    return 0;
}

