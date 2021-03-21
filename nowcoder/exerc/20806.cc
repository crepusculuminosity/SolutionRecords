#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[1 << 17], l[1 << 17], r[1 << 17];
ll n;

ll solve() {
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j > 1 && a[j - 1] <= a[i])
      j = l[j - 1];
    l[i] = j;
  }
  for (int i = n; i; i--) {
    int j = i;
    while (j < n && a[j + 1] < a[i])
      j = r[j + 1];
    r[i] = j;
  }

  ll res = 0;
  for (int i = 1; i <= n; i++)
    res += a[i] * ((i - l[i] + 1) * (r[i] - i + 1) - 1);
  return res;
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int _;
  cin >> _;
  while (_--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    ll ans = solve();
    for (int i = 1; i <= n; i++)
      a[i] = -a[i];
    cout << ans + solve() << '\n';
  }
  return 0;
}