class Solution {
  public:
    int numIdenticalPairs(vector<int>& nums) {
      map<int, int> mp;
      for(int i : nums){
        mp[i]++;
      }

      int ans = 0;
      for(auto i : mp){
        int freq = i.second;
        ans +=  (freq*(freq-1))/2;
      }

      return ans;
    }
};
