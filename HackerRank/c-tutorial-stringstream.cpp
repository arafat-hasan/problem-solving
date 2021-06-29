#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str) {
  vector<int> res;
  stringstream ss(str);
  char ch;
  for (int val; ss >> val;) {
    res.push_back(val);
    if (!(ss >> ch)) break;
  }
  return res;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }

  return 0;
}
