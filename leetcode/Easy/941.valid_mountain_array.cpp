/*
 * FILE: 941.valid_mountain_array.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/valid-mountain-array/
 * DATE CREATED: 25-01-22 23:38:29 (+06)
 * LAST MODIFIED: 26-01-22 00:57:00 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    if ((int)arr.size() < 3 || arr[0] > arr[1]) return false;
    bool increasingState = true;
    for (int i = 1; i < (int)arr.size(); i++) {
      if (increasingState) {
        if (arr[i - 1] == arr[i]) {
          return false;
        } else if (arr[i] < arr[i - 1]) {
          increasingState = false;
        }

      } else {
        if (arr[i - 1] <= arr[i]) {
          return false;
        }
      }
    }

    return !increasingState;
  }
};
