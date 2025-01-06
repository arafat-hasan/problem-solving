/*
 * FILE: 1867.Most-Frequent-Word-II.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://www.lintcode.com/problem/1867/
 * DATE CREATED: 25-02-22 17:08:56 (+06)
 * LAST MODIFIED: 25-02-22 17:40:05 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  /**
   * @param paragraph: a string
   * @return: the most frequent word
   */
  string mostCommonWord(string &paragraph) {
    for (auto &w : paragraph) {
      if (w == '!')
        w = ' ';
      else if (w == '?')
        w = ' ';
      else if (w == '\'')
        w = ' ';
      else if (w == ',')
        w = ' ';
      else if (w == ';')
        w = ' ';
      else if (w == '.')
        w = ' ';
    }

    string word = "";
    map<string, int> m;
    for (int i = 0; i < paragraph.size(); ++i) {
      if (paragraph[i] == ' ' and word.size() != 0) {
        m[word]++;
        word.clear();
      } else if (paragraph[i] != ' ')
        word += tolower(paragraph[i]);
    }
    
    if(word.size() != 0) m[word]++;

    vector<string> v;
    int mx = INT_MIN;
    for (auto i : m) {
      mx = max(mx, i.second);
    }

    for (auto i : m) {
      if (i.second == mx) v.push_back(i.first);
    }
    sort(v.begin(), v.end());
    return v[0];
  }
};
