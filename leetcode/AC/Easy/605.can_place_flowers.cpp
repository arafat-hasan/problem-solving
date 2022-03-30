/*
 * FILE: 605.can_place_flowers.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/can-place-flowers/
 * DATE CREATED: 18-01-22 15:10:34 (+06)
 * LAST MODIFIED: 18-01-22 15:10:52 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count = 0;
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for (int index = 1; index < (int)flowerbed.size() - 1; ++index) {
      if (flowerbed[index] == 0 && flowerbed[index - 1] == 0 &&
          flowerbed[index + 1] == 0) {
        count++;
        flowerbed[index] = 1;
      }
    }
    return count >= n;
  }
};
