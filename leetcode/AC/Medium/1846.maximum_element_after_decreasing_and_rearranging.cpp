class Solution_3 {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int maxval = *max_element(begin(arr), end(arr));
    int arrsize = (int) arr.size();
    cout << maxval <<  ' ' << arrsize << endl;
    return maxval > arrsize? arrsize : maxval;
  }
};

class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < (int)arr.size(); i++) {
      int diff = arr[i] - arr[i - 1];
      if (diff > 1) {
        arr[i] = arr[i - 1] + 1;
      }
    }
    return arr[arr.size() - 1];
  }
};
