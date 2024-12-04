class Solution {
  bool isArithmaticSubarray(vector<int>& nums, int l, int r) {
    vector<int> tmpvec(nums.begin() + l, nums.begin() + r + 1);
    sort(tmpvec.begin(), tmpvec.end());
    for (int i = 1; i < tmpvec.size(); i++) {
      if (tmpvec[i] - tmpvec[i - 1] != tmpvec[1] - tmpvec[0]) return false;
    }
    return true;
  }

 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<bool> res;
    for (int i = 0; i < l.size(); i++) {
      res.push_back(isArithmaticSubarray(nums, l[i], r[i]));
    }
    return res;
  }
};
