class Solution {
  public:
    int xorOperation(int n, int start) {
      int num, res = 0;
      for (int i = 0; i < n; i++) {
        num = start + 2*i;
        res = res xor num;
      }
      return res;

    }
};
