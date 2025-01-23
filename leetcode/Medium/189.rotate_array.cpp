/*
 * FILE: 189.rotate_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/rotate-array
 * DATE CREATED: 28-10-21 00:22:14 (+06)
 * LAST MODIFIED: 30-01-22 14:28:27 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k %= (int)nums.size();
    reverse(nums, 0, (int)nums.size() - 1 - k);
    reverse(nums, (int)nums.size() - k, (int)nums.size() - 1);
    reverse(nums, 0, (int)nums.size() - 1);
  }

 private:
  void reverse(vector<int>& nums, int i, int j) {
    while (i < j) {
      nums[i] = nums[i] + nums[j];
      nums[j] = nums[i] - nums[j];
      nums[i] = nums[i] - nums[j];
      i++;
      j--;
    }
  }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//        int len = (int) nums.size();
//        k %= len;
//        vector<int> tmp = nums;

//       for(int i = len - k, j = 0; j < len; i++, j++){
//         if(i == len) i = 0;
//         nums[j] = tmp[i];
//       }
//    }
//};
