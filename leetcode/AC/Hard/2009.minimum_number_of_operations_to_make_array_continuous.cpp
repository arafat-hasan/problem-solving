class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();
    set<int> unique(nums.begin(), nums.end());
    vector<int> uniqueNums(unique.begin(), unique.end());

    int maxClan = 1;
    for (int i = 0; i < (int)uniqueNums.size(); i++) {
      int start = uniqueNums[i];
      int end = start + size - 1;
      int endIdx = upper_bound(uniqueNums.begin(), uniqueNums.end(), end) -
                   uniqueNums.begin();
      int tmpClan = endIdx - i;
      maxClan = tmpClan > maxClan ? tmpClan : maxClan;
    }

    return size - maxClan;
  }
};
