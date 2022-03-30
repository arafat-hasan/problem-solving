/*
 * FILE: 819.most_common_word.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/most-common-word/
 * DATE CREATED: 25-02-22 17:51:18 (+06)
 * LAST MODIFIED: 25-02-22 17:55:35 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    for (auto& w : paragraph) {
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

    set<string> st(banned.begin(), banned.end());

    string word = "";
    map<string, int> m;
    for (int i = 0; i < paragraph.size(); ++i) {
      if (paragraph[i] == ' ' and word.size() != 0) {
        if (st.count(word) == 0) m[word]++;
        word.clear();
      } else if (paragraph[i] != ' ')
        word += tolower(paragraph[i]);
    }

    if (word.size() != 0 and st.count(word) == 0) m[word]++;

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
