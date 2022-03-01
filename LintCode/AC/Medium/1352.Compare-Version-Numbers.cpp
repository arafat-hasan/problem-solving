/*
 * FILE: 1352.Compare-Version-Numbers.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://www.lintcode.com/problem/1352/
 * DATE CREATED: 02-03-22 00:02:04 (+06)
 * LAST MODIFIED: 02-03-22 00:02:23 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  /**
   * @param version1: the first given number
   * @param version2: the second given number
   * @return: the result of comparing
   */
  Solution() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }

  int compareVersion(string version1, string version2) {
    for (auto &w : version1)
      if (w == '.') w = ' ';
    for (auto &w : version2)
      if (w == '.') w = ' ';
    istringstream s1(version1), s2(version2);

    while (1) {
      int n1, n2;
      if (not(s1 >> n1)) n1 = 0;
      if (not(s2 >> n2)) n2 = 0;

      if (not s1 and not s2) return 0;
      if (n1 < n2) return -1;
      if (n2 < n1) return 1;
    }
  }
};
