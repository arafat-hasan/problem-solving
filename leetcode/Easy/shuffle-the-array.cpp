class Solution {
  public:
    vector<int> shuffle(vector<int>& nums, int n) {
      vector<int> result;
      for(int i = 0; i < 2*n; ++i){
        result.push_back(nums[i&1? n+i/2 : i/2]);
      }
      return result;
    }
};
