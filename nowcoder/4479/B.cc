#include <bits/stdc++.h>
using namespace std;

bool isgood(int t) {
  int s = 0, t1 = t, sum = 0;
  while (t) {
    t /= 10;
    ++sum;
  }
  t = t1;
  while (t) {
    int g = 1;
    for (int i = 0; i < sum; ++i) {
      g *= (t % 10);
    }
    s += g;
    t /= 10;
  }
  return s == t1;
}
int main() {
  int n;
  cin >> n;
  int sum = 0;
  while (n--) {
    int t;
    cin >> t;
    if (isgood(t))
      ++sum;
  }
  cout << sum << endl;
  return 0;
}