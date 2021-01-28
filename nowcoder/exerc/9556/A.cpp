#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   *
   * @param arr int整型vector
   * @return int整型
   */
  typedef long long ll;
  int Answerofjudge(vector<int> &arr) {
    int len = arr.size();
    // write code here
    ll sum = 0;
    sort(arr.begin(), arr.end());
    for (auto it = arr.begin(); it != arr.end(); it++)
      sum += (*it);
    double avr = sum * 1.0 / len;
    double mid;
    if (len % 2)
      mid = arr[(len - 1) / 2];
    else
      mid = (arr[len / 2] + arr[len / 2 - 1]) / 2.0;

    if (avr > mid)
      return -1;
    if (avr == mid)
      return 0;
    else
      return 1;
  }
};

int main() {
  vector<int> v{6, 6, 6, 6, 5, 8};
  Solution s;
  s.Answerofjudge(v);
  return 0;
}