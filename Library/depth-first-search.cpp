/*
 * FILE: depth-first-search.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK:
 * DATE CREATED: 17-10-23 13:53:31 (+06)
 * LAST MODIFIED: 17-10-23 15:53:19 (+06)
 */

#include <iostream>
#include <list>
#include <map>
#include <vector>

using namespace std;

class Graph {
  int verticesCount;
  std::list<int> *adj;
  std::vector<int> *finish, *discover, *color;
  int timeTaken;

 public:
  Graph(int _verticesCount)
      : verticesCount(_verticesCount),
        adj(new std::list<int>[verticesCount]),
        finish(new std::vector<int>(verticesCount)),
        discover(new std::vector<int>(verticesCount)),
        color(new std::vector<int>(verticesCount)),
        timeTaken(0) {}

  void addEdge(int v, int w) { adj[v].push_back(w); }

  void depthFirstSearch(int src) {
    cout << src << ' ';
    timeTaken++;
    discover->at(src) = timeTaken;
    color->at(src) = 1;  /// unvisited = 0, visiting = 1, visited = 2;

    for (int v : adj[src]) {
      if (color->at(v) == 0) depthFirstSearch(v);
    }
    color->at(src) = 2;
    timeTaken++;
    finish->at(src) = timeTaken;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Graph graph(4);
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(2, 3);
  graph.addEdge(3, 3);
  std::cout << "Following depth first serach: starting from vertex 1" << std::endl;
  graph.depthFirstSearch(1);
  return 0;
}

/*
 *
 *      0
 *    ╱    ╲
 *   ╱      ╲
 *  1 ─────── 2 ────── 3 ───┐
 *                     │    │
 *                     └────┘
 */
