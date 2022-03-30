/*
 * FILE: 402.remove_k_digits.cs
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/remove-k-digits/
 * DATE CREATED: 18-02-22 16:34:46 (+06)
 * LAST MODIFIED: 18-02-22 18:30:22 (+06)
 * VERDICT: Accepetd
 */

public class Solution {
  public string RemoveKdigits(string num, int k) {
    int pivot = 0;
    while(k-- > 0){
      for(int i = pivot; i < num.Length - 1; ++i){
        if(num[i+1] < num[i]) break;
        pivot++;
      }

      num = num.Remove(pivot, 1);
      pivot -= Convert.ToInt32 (pivot != 0);

      while(num.Length > 0 && num[0] == '0'){
        num = num.Remove(0, 1);

      }

      if(num.Length == 0) break;
    }
    return num.Length == 0? "0" : num;
  }
}
