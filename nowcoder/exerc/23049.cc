#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 2e5 + 10;
constexpr ll maxl = 1e9 + 10;
ll n, k;
ll a[maxn];

bool check(ll x) {
  ll num = 0;
  for (ll i = 1; i <= n; i++)
    num += a[i] / x;
  return num >= k;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  cin >> n >> k;
  for (ll i = 1; i <= n; i++)
    cin >> a[i];

  ll l = 0, r = maxl;
  while (r - l > 1) {
    ll mid = l + r >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  cout << l;
  return 0;
}