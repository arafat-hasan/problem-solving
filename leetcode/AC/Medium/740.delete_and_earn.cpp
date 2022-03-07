/*
 * FILE: 740.delete_and_earn.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/delete-and-earn/
 * DATE CREATED: 05-03-22 19:12:51 (+06)
 * LAST MODIFIED: 05-03-22 19:13:07 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    vector<int> dp(10001, 0);
    vector<int> freq(10001, 0);

    for (int i : nums) freq[i]++;

    dp[1] = freq[1];
    for (int i = 2; i < 10001; ++i) {
      dp[i] = max(dp[i - 2] + i * freq[i], dp[i - 1]);
    }
    return dp[10000];
  }
};
