class Solution {
  public:
    int maximumWealth(vector<vector<int>>& accounts) {
      int max = 0;
      for(auto customer : accounts){
        int total = 0;
        for(auto bank : customer){
          total += bank;
          max = total > max ? total : max;
        }
      }
      return max;
    }
};
