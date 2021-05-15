#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
typedef long long ll;
ll st[maxn][20];
int Log[maxn];
ll n;
inline ll read() {
  ll x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
ll query(int l, int r) {
  int k = Log[r - l + 1];
  return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  Log[1] = 0, Log[2] = 1;
  for (int i = 3; i < maxn; i++)
    Log[i] = Log[i / 2] + 1;
  ll _ = read();
  // cin >> _;
  while (_--) {
    // memset(st, 0, sizeof(st));
    n = read();
    for (int i = 1; i <= n; i++) {
      // ll x;
      // cin >> x;
      st[i][0] = read();
    }

    for (int j = 1; j <= 17; j++) {
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        st[i][j] = __gcd(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    }

    ll ans = -1;
    for (int i = 1; i <= n; i++) {
      // if(st[i][0]==st[i-1][0]) continue;
      int j = i;
      while (j <= n) {
        ll x = query(i, j);
        int l = j, r = n + 1;
        while (r - l > 1) {
          int mid = (r + l) >> 1;
          if (query(i, mid) == x)
            l = mid;
          else
            r = mid;
        }
        ans = max(ans, (l - i + 1) * query(i, l));
        j = l + 1;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}