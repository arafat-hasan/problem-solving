#include <iostream>
#include <list>
#include <queue>

class Graph {
  int verticesCount;
  std::list<int> *adj;

 public:
  Graph(int verticesCount) {
    this->verticesCount = verticesCount;
    adj = new std::list<int>[verticesCount];
  }

  void addEdge(int v, int w) { adj[v].push_back(w); }

  void breadthFirstSearch(int src) {
    bool *visited = new bool[verticesCount];
    for (int i = 0; i < verticesCount; ++i) {
      visited[i] = false;
    }

    visited[src] = true;
    std::queue<int> q;
    q.push(src);
    while (!q.empty()) {
      src = q.front();
      std::cout << src << ' ';
      q.pop();
      for (int v : adj[src]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    std::cout << std::endl;
  }
};

int main() {
  Graph graph(4);
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);
  graph.addEdge(2, 0);
  graph.addEdge(2, 3);
  graph.addEdge(3, 3);
  std::cout << "Following bradth first serach: starting from vertex 2"
            << std::endl;
  graph.breadthFirstSearch(2);
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
         
        
       


