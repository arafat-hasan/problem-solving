/*
 * FILE: 2129.capitalize_the_title.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/capitalize-the-title/
 * DATE CREATED: 12-01-22 17:56:26 (+06)
 * LAST MODIFIED: 12-01-22 17:56:45 (+06)
 * VERDICT: Accepetd
 */

class Solution {
 public:
  string capitalizeTitle(string title) {
    vector<string> tokens = split(&title, ' ');
    string res = "";
    bool flag = true;
    for (string item : tokens) {
      if (!flag)
        res += " ";
      else
        flag = false;
      transformLower(&item);
      if ((int)item.size() > 2) {
        item[0] = toupper(item[0]);
      }
      res += item;
    }
    return res;
  }

 private:
  void transformLower(string *item) {
    for (size_t i = 0; i < item->size(); ++i) {
      (*item)[i] = tolower((*item)[i]);
    }
  }

  vector<string> split(string *str, char delim) {
    vector<string> res;
    stringstream ss((*str));
    string item;
    while (getline(ss, item, delim)) {
      res.push_back(item);
    }
    return res;
  }
};
