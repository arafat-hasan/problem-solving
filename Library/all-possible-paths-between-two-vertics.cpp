/*
 * FILE: all-possible-paths-between-two-vertices.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * DATE CREATED: 19-11-21 17:18:05 (+06)
 * LAST MODIFIED: 19-11-21 17:18:31 (+06)
 */

#include <stdint.h>  //uint32_t
#include <unistd.h>  // unsigned int sleep(unsigned int seconds);

#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>  // std::istream_iterator
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Graph {
 public:
  Graph(int vertices) {
    m_vertices = vertices;
    m_neighbours = new list<int>[vertices];
  }
  void addEdge(int src, int des) { m_neighbours[src].push_back(des); }
  int countPaths(int src, int des, int vertices) {
    int pathCount = 0;
    vector<bool> visited(vertices, false);
    pathCounter(src, des, pathCount, visited);
    return pathCount;
  }

 private:
  list<int>* m_neighbours;
  int m_vertices;
  void pathCounter(int src, int des, int& pathCount, vector<bool>& visited) {
    visited[src] = true;
    if (src == des) {
      pathCount++;
    } else {
      for (int neighbour : m_neighbours[src]) {
        if (!visited[neighbour]) {
          pathCounter(neighbour, des, pathCount, visited);
        }
      }
    }
    visited[src] = false;
  }
};

int main() {
  Graph graph(5);

  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(0, 4);
  graph.addEdge(1, 3);
  graph.addEdge(1, 4);
  graph.addEdge(2, 3);
  graph.addEdge(2, 1);
  graph.addEdge(3, 2);

  cout << graph.countPaths(0, 4, 5) << endl;
  return 0;
}
