#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int dfs(ll x, ll y) {
  if (y == 1 || y == 2 * x - 1)
    return 1;
  if (x < 1 || y > 2 * x - 1)
    return 0;
  return dfs(x - 1, y) + dfs(x - 1, y - 1) + dfs(x - 1, y - 2);
}

int main() {
  ll n;
  while (cin >> n) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      if (dfs(n, j) % 2 == 0) {
        cout << j << '\n';
        break;
      } else if (j == 2 * n - 1)
        cout << -1 << '\n';
    }
  }
  return 0;
}