#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e7 + 10;
int a[maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}
void init() {
  for (int i = 1; i <= maxn / 2; i++) {
    for (int j = i + i; j < maxn; j += i)
      if ((j ^ i) == j - i)
        ++a[j];
  }
  for (int i = 2; i < maxn; i++)
    a[i] += a[i - 1];
}
int main() {
  //freopen("data.in","r",stdin);
  //freopen("data.out","w",stdout);
  init();
  int _ = read(), kse = 1;
  while (_--) {
    int n = read();
    printf("Case %d: %d\n", kse++, a[n]);
  }
  return 0;
}