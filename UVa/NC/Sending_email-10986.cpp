/*
 * FILE: Sending_email-10986.cpp
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 06-07-17 17:20:37 (BST)
 * LAST MODIFIED: 12-07-17 13:50:40 (BST)
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
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

using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<int, int> pii;
typedef vector <pii> vpii;
typedef vector <int> vi;

#define ull unsigned long long

#define __FastIO ios_base::sync_with_stdio(false); cin.tie(0)

#define For(i, a, b) for (__typeof (a) i=a; i<=b; i++)
#define Rof(i, b, a) for (__typeof (a) i=b; i>=a; i--)
#define Rep(i, n) for (__typeof (n) i=0; i<n; i++)
#define Forit(i, s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar) ar.begin(), ar.end()
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define clr(a) memset(a, 0, sizeof a)
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

////////////////////// Code starts here ///////////////////////

void dijkstra(int s, vi *dist, vector<vpii> *graph) {
    priority_queue< pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        pii front = pq.top();
        pq.pop();
        int d = front.first, u = front.second;
        if (d == dist->at(u)) {
            for (int j = 0; j < (int) graph->at(u).size(); j++) {
                pii v = graph->at(u)[j];    // all outgoing edges from u
                if (dist->at(u) + v.second < dist->at(v.first)) {
                    dist->at(v.first) = dist->at(u) + v.second;     // relax operation
                    pq.push(pii(dist->at(v.first), v.first));
                }
            }
        }
    }
}

int main() {
    int N, cases = 1;
    cin >> N;
    while (N--) {
        int n, m, s, t;

        cin >> n >> m >> s >> t;
        vector<vpii> graph (n, vpii());
        int u, v, w;
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> w;
            //connected by a bidirectional cable
            graph[u].push_back(pii(v, w));
            graph[v].push_back(pii(u, w));
        }
        vi dist(n, INF);
        dist[s] = 0;
        dijkstra(s, &dist, &graph);
        if (dist[t] != INF) {
            cout << "Case #" << cases++ <<  ": " << dist[t] << '\n';
        } else {
            cout << "Case #" << cases++ << ": unreachable\n";
        }
    }
    return 0;
}
