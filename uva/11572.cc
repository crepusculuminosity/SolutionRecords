#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int a[maxn];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    int l = 1, r = 1, ans = 0;
    set<int> s;
    while (r <= n) {
      while (r <= n && !s.count(a[r]))
        s.insert(a[r++]);
      ans = max(ans, r - l);
      s.erase(a[l++]);
    }
    cout << ans << '\n';
  }
  return 0;
}