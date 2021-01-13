#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, h, w, n;
  cin >> t;
  while (t--) {
    cin >> w >> h >> n;
    int res = 1;
    while (!(w & 1)) {
      w /= 2;
      res *= 2;
    }
    while (!(h & 1)) {
      h /= 2;
      res *= 2;
    }
    cout << ((res >= n) ? "YES\n" : "NO\n");
  }
  return 0;
}
