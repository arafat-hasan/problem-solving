class Solution {
  public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
      vector<int> target;
      for(int i = 0; i < (int) nums.size(); ++i){
        target.insert(target.begin() + index[i], nums[i]);
      }
      return target;
    }
};
