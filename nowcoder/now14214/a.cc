#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll a[N], n;
template <typename T, typename... Ts> inline void read(T &x, Ts &...args) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (isdigit(ch))
    x = x * 10 + ch - 48, ch = getchar();
  if constexpr (sizeof...(args))
    read(args...);
}
int main() {
  read(n);
  for (ll i = 1; i <= n; i++)
    read(a[i]);
  sort(a + 1, a + 1 + n);
  ll ans = -1;
  int i = 1;
  while (i <= n) {
    int j = i;
    while (a[j] == a[j + 1])
      ++j;
    ans = max(ans, (j - i + 1) * a[i]);
    i = ++j;
  }
  printf("%lld", ans);
  return 0;
}