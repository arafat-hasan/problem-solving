/*
 * FILE: 881.boats_to_save_people.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/boats-to-save-people/
 * DATE CREATED: 24-03-22 11:56:36 (+06)
 * LAST MODIFIED: 24-03-22 17:42:08 (+06)
 * VERDICT: Accepetd
 */


class Solution {
  public int numRescueBoats(int[] people, int limit) {
    int start = 0, end = people.length - 1, cnt = 0;
    Arrays.sort(people);

    while(start <= end){
      if(people[start] + people[end] <= limit){
        start++;
        end--;
      }else{
        end--;
      }
      cnt++;
    }
    return cnt;
  }
}
