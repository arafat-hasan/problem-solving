class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& nums,
                                  vector<vector<int>>& queries) {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i] & 1 ? 0 : nums[i];
    }

    vector<int> res;
    for (int i = 0; i < queries.size(); i++) {
      int val = queries[i][0];
      int idx = queries[i][1];
      if (!(nums[idx] & 1)) sum -= nums[idx];
      nums[idx] += val;
      if (!(nums[idx] & 1)) sum += nums[idx];
      res.push_back(sum);
    }

    return res;
  }
};
