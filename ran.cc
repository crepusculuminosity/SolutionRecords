#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010];
constexpr int INF = 0x7fffffff;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("input.txt", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = a[i - 1] + x;
  }
  int ans = -INF;
  for (int i = 1; i + k - 1 <= n; i++)
    ans = max(ans, a[i + k - 1] - a[i - 1]);
  cout << ans << '\n';
  return 0;
}