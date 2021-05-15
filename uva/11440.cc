#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 100000007; //模数是1e8+7！！！
constexpr int maxn = 1e7 + 10;
using ll = long long;
int cnt, num[maxn], prime[maxn], f[maxn];
int m, n;

void init() {
  f[1] = 1;
  for (int i = 2; i < maxn; i++) {
    if (!num[i])
      prime[++cnt] = i, f[i] = (ll)f[i - 1] * (i - 1) % mod;
    else
      f[i] = (ll)f[i - 1] * i % mod;
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
}

int main() {
  init();
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  while (cin >> n >> m && m + n) {
    int ans = f[m];
    for (int i = m + 1; i <= n; i++)
      ans = (ll)ans * i % mod;
    cout << ans - 1 << '\n';
  }
  return 0;
}