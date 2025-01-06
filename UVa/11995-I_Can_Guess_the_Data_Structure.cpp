/*
 * FILE: I_Can_Guess_the_Data_Structure-11995.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://onlinejudge.org/external/119/11995.pdf
 *
 * DATE CREATED: 22-02-20 22:45:52 (+06)
 * LAST MODIFIED: 23-02-20 01:43:16 (+06)
 *
 * VERDICT: Accepetd
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 22-02-20     1.0         Deleted code is debugged code.
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
 */

///////////////////////////////////////////////////////////////////////

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  while (cin >> n) {
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;
    tuple<bool, bool, bool> state = make_tuple(true, true, true);
    int cmd, x;

    while (n--) {
      cin >> cmd >> x;
      if (cmd == 1) {
        if (get<0>(state)) st.push(x);
        if (get<1>(state)) q.push(x);
        if (get<2>(state)) pq.push(x);
      } else if (cmd == 2) {
        if (get<0>(state)) {
          if (st.empty() or st.top() != x)
            get<0>(state) = false;
          else
            st.pop();
        }

        if (get<1>(state)) {
          if (q.empty() or q.front() != x)
            get<1>(state) = false;
          else
            q.pop();
        }

        if (get<2>(state)) {
          if (pq.empty() or pq.top() != x)
            get<2>(state) = false;
          else
            pq.pop();
        }
      }
    }

    int sum = get<0>(state) + get<1>(state) + get<2>(state);

    if (sum >= 2) {
      cout << "not sure\n";
    } else if (sum == 0) {
      cout << "impossible\n";
    } else if (sum == 1) {
      if (get<0>(state) == 1)
        cout << "stack\n";
      else if (get<1>(state) == 1)
        cout << "queue\n";
      else if (get<2>(state) == 1)
        cout << "priority queue\n";
    }
  }

  return 0;
}
