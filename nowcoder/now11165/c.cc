#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int maxn = 1e6 + 10;
ll b[maxn];
int n;
ll sum;
template <typename T> inline void read(T &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
}

int main() {
  freopen("data.in", "r", stdin);
  read<int>(n);
  for (int i = 1; i <= n; i++) {
    read<ll>(b[i]);
    sum += b[i];
  }
  sum /= n;
  for (int i = 1; i < n; i++) {
    b[i] = b[i - 1] + b[i] - sum;
  }
  sort(b, b + n);
  ll cur = b[n / 2], ans = 0;
  for (int i = 0; i < n; i++)
    ans += abs(cur - b[i]);
  printf("%lld", ans);
  return 0;
}