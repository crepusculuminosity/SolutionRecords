#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int> &nums, int k) {
  // int sum[100010]; sum[0]=0;
  sort(nums.begin(), nums.end());
  vector<int> a, sum;
  for (int i = 1; i < nums.size(); i++)
    a.push_back(nums[i] - nums[i - 1]);
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    if (i == 0)
      sum.push_back(a[i]);
    else
      sum.push_back(sum[i - 1] + a[i]);
  }
  if (k >= sum[sum.size() - 1])
    return nums.size();
  int m = lower_bound(sum.begin(), sum.end(), k) - sum.begin();
  return m + 1;
}

int main() {
  freopen("data.out", "w", stdout);
  vector<int> a{9930, 9923, 9983,  9997, 9934, 9952, 9945, 9914, 9985, 9982,
                9970, 9932, 9985,  9902, 9975, 9990, 9922, 9990, 9994, 9937,
                9996, 9964, 9943,  9963, 9911, 9925, 9935, 9945, 9933, 9916,
                9930, 9938, 10000, 9916, 9911, 9959, 9957, 9907, 9913, 9916,
                9993, 9930, 9975,  9924, 9988, 9923, 9910, 9925, 9977, 9981,
                9927, 9930, 9927,  9925, 9923, 9904, 9928, 9928, 9986, 9903,
                9985, 9954, 9938,  9911, 9952, 9974, 9926, 9920, 9972, 9983,
                9973, 9917, 9995,  9973, 9977, 9947, 9936, 9975, 9954, 9932,
                9964, 9972, 9935,  9946, 9966};
  cout << a.size() << endl;
  cout << maxFrequency(a, 3056);
  return 0;
}