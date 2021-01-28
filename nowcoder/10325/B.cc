#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;
double f[MAXN];
int main() {
  for (int i = 1; i < MAXN; i++) {
    f[i] = f[i - 1] + 1.0 / i;
  }
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    double ans = f[n] * (n + 9999);
    printf("%.7lf\n", ans);
  }
  return 0;
}