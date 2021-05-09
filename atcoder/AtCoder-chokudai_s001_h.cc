#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int a[maxn], g[maxn];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  memset(g, 0x3f, sizeof(g));
  for (int i = 1; i <= n; i++) {
    int k = lower_bound(g + 1, g + n + 1, a[i]) - g - 1;
    cout << k << ' ';
    g[k] = a[i];
  }
  return 0;
}