#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
ll a[MAXN];
int n;

inline ll read() {
  ll x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  freopen("data.in", "r", stdin);
  n = read();
  bool x, y, z;
  x = y = z = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  for (int i = 2; i <= n - 2; i++) {
    if (a[i + 1] + a[i - 1] != a[i] * 2)
      x = 0;
    if (a[i + 1] * a[i - 1] != a[i] * a[i])
      y = 0;
    if (a[i] % a[i - 1] != a[i + 1] % a[i])
      z = 0;
  }
  if (x + y + z)
    puts("YES");
  else
    puts("NO");
  return 0;
}