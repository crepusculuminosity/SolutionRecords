#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5 + 10;
using ll = long long;
int n;
ll a[maxn], c[maxn];

int main() {

  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    c[i] = a[i] - x;
  }
  sort(c + 1, c + 1 + n);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll m = upper_bound(c + i + 1, c + 1 + n, -c[i]) - c;
    ans += n - m + 1;
  }
  cout << ans;
  return 0;
}