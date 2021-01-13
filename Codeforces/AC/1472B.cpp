#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, tmp;
  cin >> t;
  while (t--) {
    cin >> n;
    int ones = 0, twos = 0;
    while (n--) {
      cin >> tmp;
      tmp == 1 ? ones++ : twos++;
    }
    int sum = ones + twos * 2;
    if (sum % 2 == 0 and (ones > 0 or twos % 2 == 0))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
