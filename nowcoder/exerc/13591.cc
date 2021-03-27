#include <bits/stdc++.h>
using namespace std;

int n, m;
constexpr int maxn = 1e5 + 10;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n >> m) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n;) {
      if (a[i + 1] - a[i] < m) {
        i += 2;
        ++ans;
      } else
        ++i;
    }
    cout << ans << '\n';
  }
  return 0;
}