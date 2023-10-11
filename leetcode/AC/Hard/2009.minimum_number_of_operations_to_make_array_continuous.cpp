class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int size = nums.size();
    set<int> unique(nums.begin(), nums.end());
    vector<int> uniqueNums(unique.begin(), unique.end());
    for(auto i : uniqueNums) cout << i << ' ';
    cout << endl;

    int maxClan = 1;
    for (int i = 0; i < (int)uniqueNums.size(); i++) {
      int start = uniqueNums[i];
      int end = start + size - 1;
      int endIdx = uniqueNums.begin() -
                   upper_bound(uniqueNums.begin(), uniqueNums.end(), end);
      int tmpClan = endIdx - i;
      maxClan = tmpClan > maxClan ? tmpClan : maxClan;
      cout << start << ' ' << end << ' ' << endIdx << ' ' << tmpClan << endl;
    }

    return size - maxClan;
  }
};
