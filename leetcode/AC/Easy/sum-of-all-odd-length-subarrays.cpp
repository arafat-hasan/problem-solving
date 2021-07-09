class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int ans = 0, n = (int)arr.size();
    for (int i = 0; i < n; i++) {
      int occur = ceil(((i + 1) * (n - i)) / 2.0);
      ans += (arr[i] * occur);
    }
    return ans;
  }
};
