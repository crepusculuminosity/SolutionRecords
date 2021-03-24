#include <bits/stdc++.h>
using namespace std;
constexpr double eps = 1e-3;
int main() {
  double x, u;
  cin >> u;
  double l = -100, r = 100, mid;
  while (r - l > eps) {
    mid = (r + l) / 2;
    if (mid * mid * mid > u)
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(1) << mid;
  return 0;
}