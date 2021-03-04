#include <cmath>
#include <cstdio>

typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 105;

namespace prime {
ll phi[maxn][maxm];
int p[maxn], pi[maxn * 10], cnt;
bool vis[maxn * 10];

inline void init() {
  for (int i = 2; i < maxn * 10; ++i) {
    if (!vis[i])
      p[++cnt] = i;
    pi[i] = cnt;
    for (int j = 1; j <= cnt && i * p[j] < maxn * 10; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0)
        break;
    }
  }

  for (int n = 0; n < maxm; ++n)
    for (int m = 0; m < maxn; ++m)
      if (!n)
        phi[m][n] = m;
      else
        phi[m][n] = phi[m][n - 1] - phi[m / p[n]][n - 1];
}

inline ll Phi(ll m, int n) {
  if (n == 0)
    return m;
  else if (p[n] >= m)
    return 1;
  else if (m < maxn && n < maxm)
    return phi[m][n];
  return Phi(m, n - 1) - Phi(m / p[n], n - 1);
}

inline ll Pi(ll m) {
  if (m < maxn)
    return pi[m];
  int s = sqrt(m), y = cbrt(m), n = pi[y];
  ll res = Phi(m, n) + n - 1;
  for (int i = n + 1; p[i] <= s; ++i)
    res -= Pi(m / p[i]) - Pi(p[i]) + 1;
  return res;
}
} // namespace prime

ll n, res;
int p[maxn * 10], cnt, ntc;
bool vis[maxn * 10];

inline void SK() {
  scanf("%lld", &n);
  res = prime::Pi(n);
  ll maxn = sqrt(n);
  cnt = 0;
  for (int i = 2; i <= maxn; ++i) {
    if (!vis[i]) {
      p[++cnt] = i;
      ll temp = 1ll * i * i;
      while (temp <= n) {
        ++ntc;
        temp *= i;
      }
    }
    for (int j = 1; j <= cnt && i * p[j] <= maxn; ++j) {
      vis[i * p[j]] = 1;
      if (i % p[j] == 0)
        break;
    }
  }
}

int main() {
  prime::init();
  SK();
  printf("%lld\n", res + ntc);
}