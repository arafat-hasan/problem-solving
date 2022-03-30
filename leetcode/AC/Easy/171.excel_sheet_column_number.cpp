/*
 * FILE: 171.excel_sheet_column_number.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/excel-sheet-column-number/
 * DATE CREATED: 22-02-22 22:08:20 (+06)
 * LAST MODIFIED: 22-02-22 22:16:46 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int res = 0;
    for (char i : columnTitle) {
      int d = i - 'A' + 1;
      res = res * 26 + d;
    }
    return res;
  }
};
