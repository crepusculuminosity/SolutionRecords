#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005], c, n;

inline ll read() {
  ll x = 0;
  int f = 1; //
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

bool check(ll x) {
  int tot = 1, num = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] - a[num] >= x) {
      tot++;
      num = i;
    }
  }
  return tot >= c;
}

int main() {
  n = read();
  c = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a + 1, a + n + 1);
  ll l = 1, r = a[n] - a[1];
  while (l <= r) {
    ll mid = (r + l) >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
    /* code */
  }
  printf("%lld\n", l - 1);
  return 0;
}