#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

long long n, x, minn, maxn;
int main() {
  n = read();
  ll a = read(), b = read();
  minn = min(a, b);
  maxn = b - a;
  for (int i = 3; i <= n; i++) {
    x = read();
    minn = min(minn, x);
    maxn = max(maxn, x - minn);
  }
  cout << maxn;
  return 0;
}