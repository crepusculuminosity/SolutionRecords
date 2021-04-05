#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int a[maxn], f[maxn], g[maxn];

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  f[1] = g[1] = a[1];
  f[2] = max(a[1], a[2]), g[2] = min(a[1], a[2]);
  for (int i = 2; i < n; i++) {
    if (a[i + 1] >= f[i])
      f[i + 1] = a[i + 1], g[i + 1] = f[i];
    else {
      f[i + 1] = f[i];
      g[i + 1] = max(a[i + 1], g[i]);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << g[x] << '\n';
  }
  return 0;
}