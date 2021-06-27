/*
 * FILE: attribute-parser.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://www.hackerrank.com/challenges/attribute-parser/problem
 * DATE CREATED: 27-06-21 16:16:12 (+06)
 * LAST MODIFIED: 27-06-21 18:05:07 (+06)
 * VERDICT: Accepetd
 * VERSION: 1.0
 * DESCRIPTION: Deleted code is debugged code.
 */

#include <stdint.h>  //uint32_t
#include <unistd.h>  // unsigned int sleep(unsigned int seconds);

#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>  // std::istream_iterator
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef vector<long long> vl;

#define _USE_MATH_DEFINES

#define forr(i, a, b) for (__typeof(a) i = (a); i <= (b); i++)
#define rof(i, b, a) for (__typeof(a) i = (b); i >= (a); i--)
#define rep(i, n) for (__typeof(n) i = 0; i < (n); i++)
#define forit(i, s) \
  for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar) ar.begin(), ar.end()
#define fill(a, val) memset((a), (val), sizeof((a)))
#define clr(a) memset((a), 0, sizeof((a)))
#define sz(a) (int)a.size()

#define pb push_back

#ifndef ONLINE_JUDGE
#define nl cerr << '\n'
#define sp cerr << ' '
#define ckk cerr << "###############\n"
#define debug1(x) cerr << #x << ": " << (x) << '\n'
#define debug2(x, y) \
  cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
#define debug3(x, y, z)                                                        \
  cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " \
       << (z) << '\n'
#else
#define nl
#define sp
#define ckk
#define debug1(x)
#define debug2(x, y)
#define debug3(x, y, z)
#endif

#define PI acos(-1.0)
#define INF 0x7fffffff
#define MOD 1000000007
#define EPS 1e-7
#define MAX 10000007  // 1e7+7

////////////////////////// START HERE //////////////////////////

vector<string> split(const string &s, char delim = ' ') {
  vector<string> res;
  stringstream ss(s);
  string item;
  while (getline(ss, item, delim)) {
    res.push_back(item);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  string tmp;
  vector<string> hrml;
  vector<string> query;
  cin >> n >> q;
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, tmp);
    hrml.push_back(tmp);
  }

  for (int i = 0; i < q; i++) {
    cin >> tmp;
    query.push_back(tmp);
  }

  map<vector<string>, map<string, string>> attributes;
  vector<string> currentTags;

  for (int i = 0; i < n; i++) {
    tmp = hrml[i];

    tmp.erase(remove(tmp.begin(), tmp.end(), '<'), tmp.end());
    tmp.erase(remove(tmp.begin(), tmp.end(), '>'), tmp.end());
    tmp.erase(remove(tmp.begin(), tmp.end(), '"'), tmp.end());
    tmp.erase(remove(tmp.begin(), tmp.end(), '='), tmp.end());
    replace(tmp.begin(), tmp.end(), '\t', ' ');
    tmp.erase(std::unique(tmp.begin(), tmp.end(),
                          [](char a, char b) { return a == ' ' && b == ' '; }),
              tmp.end());
    if (tmp[0] == ' ') tmp.erase(0, 1);
    size_t hasEndSlash = tmp.find('/');
    if (hasEndSlash != string::npos) {
      tmp.erase(remove(tmp.begin(), tmp.end(), '/'), tmp.end());
      currentTags.pop_back();
      continue;
    }

    vector<string> splitElems = split(tmp);
    currentTags.push_back(splitElems[0]);
    map<string, string> tmpMap;
    for (int j = 1; j < (int)splitElems.size() - 1; j += 2) {
      tmpMap[splitElems[j]] = splitElems[j + 1];
    }
    attributes[currentTags] = tmpMap;
  }

  for (int i = 0; i < q; i++) {
    tmp = query[i];
    string attributeName = tmp.substr(tmp.find('~') + 1);
    tmp.erase(tmp.find('~'));
    vector<string> tagName = split(tmp, '.');
    if (attributes.count(tagName) == 0 or
        attributes[tagName].count(attributeName) == 0)
      cout << "Not Found!\n";
    else
      cout << attributes[tagName][attributeName] << endl;
  }

  return 0;
}
