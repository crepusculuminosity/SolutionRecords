#include <bits/stdc++.h>
using namespace std;
int n;
constexpr int maxn = 1e5 + 1000;
int a[maxn];

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0')
    ch = getchar();
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  int g = abs(a[2] - a[1]);
  for (int i = 2; i <= n; i++) {
    g = __gcd(g, abs(a[i] - a[1]));
  }
  printf("%d %d", g, (g - a[1] % g) % g);
  return 0;
}