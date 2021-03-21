#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
ll a[MAXN];
ll cnt;

inline ll read() {
  ll x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

void out(ll x) {
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  ll n = read(), x = read(), y = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a + 1, a + n + 1);
  int m;
  for (int i = 1; i <= n; i++) {
    int s = lower_bound(a + 1 + i, a + 1 + n, x - a[i]) - a;
    int t = upper_bound(a + 1 + i, a + 1 + n, y - a[i]) - a;
    int m = t - s;
    // out(s); putchar('\n');
    // out(t); putchar('\n');
    cnt += m;
  }

  out(cnt);
  putchar('\n');
  return 0;
}