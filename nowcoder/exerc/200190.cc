#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll sh[20], sl[20];
ll a[20][20];
bool b[20];
ll n, m, k;
ll ans = 0;

ll conv(ll x) {
  memset(b, 0, sizeof(b));
  ll cnt = 0, i = 1;
  while (x) {
    if (x & 1)
      ++cnt, b[i] = 1;
    x >>= 1;
    ++i;
  }
  return cnt;
}

void init() {
  cin >> n >> m >> k;
  for (ll i = 1; i <= n; i++)
    for (ll j = 1; j <= m; j++) {
      cin >> a[i][j];
      sh[i] += a[i][j];
    }
  if (k > n)
    k = n;
  if (k > m)
    k = m;
}
int main() {
  freopen("data.in", "r", stdin);
  init();
  for (ll S = 0; S < (1 << n); S++) {
    ll n1 = conv(S);
    ll n2 = k - n1;
    ll sum = 0;
    if (n2 > m || n2 < 0)
      continue;
    for (ll i = 1; i <= n; i++)
      if (b[i])
        sum += sh[i];
    memset(sl, 0, sizeof(sl));
    for (ll i = 1; i <= n; i++)
      for (ll j = 1; j <= m; j++)
        if (!b[i])
          sl[j] += a[i][j];
    sort(sl + 1, sl + 1 + m);
    for (ll i = 1, j = m; i <= n2; i++, j--)
      sum += sl[j];
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}