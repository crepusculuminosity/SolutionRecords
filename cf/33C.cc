#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int n, sum, ans, res;

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += x, res = max(res + x, 0), ans = max(ans, res);
  }
  cout << ans * 2 - sum;
  return 0;
}