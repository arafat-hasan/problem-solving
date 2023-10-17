class Graph {
  int verticesCount;
  list<int>* adj;
  vector<int>* color;

 public:
  Graph(int _verticesCount)
      : verticesCount(_verticesCount),
        adj(new list<int>[verticesCount]),
        color(new vector<int>(verticesCount)) {}

  void addEdge(int v, int w) { adj[v].push_back(w); }

  bool depthFirstSearch(int src) {
    color->at(src) = 1;

    bool res = true;
    for (int v : adj[src]) {
      if (color->at(v) == 0) {
        res = depthFirstSearch(v);
      } else
        res = false;
    }
    color->at(src) = 2;

    return res;
  }

  bool isAllNodeVisited() {
    for (auto i : *color)
      if (i == 0) return false;
    return true;
  }
};

class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    Graph graph(n);
    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) graph.addEdge(i, leftChild[i]);
      if (rightChild[i] != -1) graph.addEdge(i, rightChild[i]);
    }

    return graph.depthFirstSearch(0) && graph.isAllNodeVisited();
  }
};
