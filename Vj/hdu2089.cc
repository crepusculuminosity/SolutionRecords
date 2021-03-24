#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int f[maxn];
int judge(int x) {
  while (x) {
    if (x % 10 == 4 || x % 100 == 62)
      return 0;
    x /= 10;
  }
  return 1;
}

int main() {
  // freopen("data.in", "r", stdin);
  f[1] = 1;
  for (int i = 2; i < maxn; i++)
    f[i] = f[i - 1] + judge(i);
  int n, m;
  while (cin >> n >> m) {
    if (m == 0 && n == 0)
      break;
    cout << f[m] - f[n - 1] << endl;
  }
  return 0;
}