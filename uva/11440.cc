#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll maxn = 1e7 + 10;
constexpr ll mod = 1e9 + 7;
ll n, m;
ll num[maxn], prime[700000], cnt;
ll f[maxn];
void init() {
  f[1] = 1;
  for (ll i = 2; i < maxn; i++) {
    if (!num[i])
      prime[++cnt] = i, f[i] = f[i - 1] * (i - 1) % mod;
    else
      f[i] = f[i - 1] * i % mod;
    for (ll j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j])
        break;
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  while (cin >> n >> m && n + m) {
    ll ans = f[m] % mod;
    for (ll i = m + 1; i <= n; i++)
      ans = ((ans%mod) * i) % mod;

    cout << (ans - 1 + mod) % mod << '\n';
  }
  return 0;
}