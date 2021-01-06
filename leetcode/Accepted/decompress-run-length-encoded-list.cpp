class Solution {
  public:
    vector<int> decompressRLElist(vector<int>& nums) {
      vector<int> result;
      for(int i = 0, j = 1; j < (int) nums.size(); i+=2, j+=2){
        for(int k = 0; k < nums[i]; ++k){
          result.push_back(nums[j]);
        }
      }
      return result;
    }
};
