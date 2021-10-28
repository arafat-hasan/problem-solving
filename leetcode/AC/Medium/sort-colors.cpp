/*
 * FILE: sort-colors.cpp
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 * LINK: https://leetcode.com/problems/sort-colors
 * DATE CREATED: 27 Oct 2021
 * LAST MODIFIED: 27 Oct 2021
 * VERDICT: Accepetd
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


class Solution {
public:
    void sortColors(vector<int>& nums) {
      for(int i = 0; i < (int) nums.size(); i++){
        for(int j = 1; j < (int) nums.size(); j++){
            if(nums[j] < nums[j - 1]){
                int tmp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tmp;
            }
        }
      }
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
      int ones = 0, zeros = 0;
      for(int i = 0; i < (int) nums.size(); i++){
        if(nums[i] == 1) ones++;
        else if(nums[i] == 0) zeros++;
      }
      for(int i = 0; i < (int) nums.size(); i++){
        if(zeros > 0){
          nums[i] = 0;
          zeros--;
        }else if(ones > 0){
          nums[i] = 1;
          ones--;
        }else{
          nums[i] = 2;
        }
      }
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Solution obj;
  vector<int> v = {2,0,2,1,1,0};
  obj.sortColors(v);
  for(auto i : v) cout << i << ' ';
  cout << endl;
  return 0;
}
