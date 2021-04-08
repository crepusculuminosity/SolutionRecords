#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e8;
using ui = uint32_t;
ui a[maxn];
// ui b[maxn];

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  a[1] = a[0] = 1;
  string str;
  // b[1] = 1;
  for (int i = 2; i <= maxn; i++) {
    if (i % 2)
      a[i] = a[i - 1];
    else
      a[i] = a[i - 1] + a[i >> 1];
    // b[i] = b[i - 1] + a[i];
  }
  ui n;
  while (cin >> n) {
    if (n <= maxn)
      cout << a[n];
    else {
      ui ans = 0;
      for (int i = 0; i <= (n >> 1); i++)
        ans += a[i];
      cout << ans;
    }
    cout << '\n';
  }
  return 0;
}