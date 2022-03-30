class Solution {
 public:
  bool checkValid(vector<vector<int>>& matrix) {
    resetSet((int)matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (!checkSet(matrix[i][j])) return false;
      }
      if (check.size() != 0) return false;
      resetSet((int)matrix.size());
    }

    resetSet((int)matrix.size());
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (!checkSet(matrix[j][i])) return false;
      }
      if (check.size() != 0) return false;
      resetSet((int)matrix.size());
    }
    return true;
  }

 private:
  set<int> check;
  bool checkSet(int n) {
    if (check.count(n) != 0) {
      check.erase(n);
      return true;
    } else {
      return false;
    }
  }

  void resetSet(int n) {
    check.clear();
    for (int i = 1; i <= n; i++) {
      check.insert(i);
    }
  }
};
