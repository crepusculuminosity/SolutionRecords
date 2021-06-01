#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn], n, L[maxn], R[maxn];
ll sum[maxn];

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}

int main() {
  // freopen("feelgood.in", "r", stdin);
  // freopen("feelgood.out", "w", stdout);
  int T = 0;
  // n = read();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    a[i] = read(), sum[i] = sum[i - 1] + 1LL * a[i];
  a[0] = a[n + 1] = -1;
  for (int i = 1; i <= n + 1; i++) {
    while (!s.empty() && a[s.top()] > a[i])
      R[s.top()] = i, s.pop();
    s.push(i);
  }
  for (int i = n; i >= 0; i--) {
    while (!s.empty() && a[s.top()] > a[i])
      L[s.top()] = i, s.pop();
    s.push(i);
  }
  ll ans = -1;
  int l, r;
  for (int i = 1; i <= n; i++) {
    if (ans < 1LL * a[i] * (sum[R[i] - 1] - sum[L[i]])) {
      ans = 1LL * a[i] * (sum[R[i] - 1] - sum[L[i]]), l = L[i] + 1,
      r = R[i] - 1;
    }
  }
  printf("%lld\n", ans);
  printf("%d %d\n", l, r);

  return 0;
}