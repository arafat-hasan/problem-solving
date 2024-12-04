/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
  int getTopIdx(MountainArray &mountainArr){
    int low = 0;
    int high = mountainArr.length();

    while(low < high){
      int mid = low + (high - low) / 2;
      int leftVal = mountainArr.get(mid-1);
      int rightVal = mountainArr.get(mid+1);
      int midVal = mountainArr.get(mid);

      if(leftVal < midVal and rightVal < midVal){
        return mid;
      }
    }


  }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
      int topIdx = getTopIdx(mountainArr);
      return 1;
    }
};
