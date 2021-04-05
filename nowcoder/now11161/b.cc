#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 7;
using ll = long long;
constexpr ll mod = 1e9 + 7;
ll n;
ll a[maxn], b[maxn];

ll qsm(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res % mod;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = n; i > 1; i--)
    b[i] = (b[i + 1] + a[i]) % mod;
  ll ans = 1;
  for (int i = 2; i <= n; i++) {
    ans = ans * a[i] % mod;
    ans = ans * qsm(b[i], mod - 2) % mod;
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  solve();
  return 0;
}