class Solution {
  public:
    int balancedStringSplit(string s) {
      int res = 0, count = 0;
      for(char ch:s){
        count += ch=='R'? 1 : -1;
        res += count == 0;
      }
      return res;
    }
};
