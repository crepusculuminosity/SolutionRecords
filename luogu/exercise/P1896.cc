#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int f[maxn];
int ans;
int n;
template <typename T> void read(T &res) {
  res = 0;
  char c = getchar();
  while (!isdigit(c))
    c = getchar();
  while (isdigit(c))
    res = (res << 1) + (res << 3) + c - 48, c = getchar();
}

int main() {
  read(n);
  while (n--) {
    int x;
    read(x);
    int re = 1;
    for (int i = 0; i <= 30; i++)
      if (x & (1 << i))
        re = max(re, f[i] + 1);
    for (int i = 0; i <= 30; i++)
      if (x & (1 << i))
        f[i] = max(f[i], re);
  }
  for (int i = 0; i <= 30; i++)
    ans = max(ans, f[i]);
  printf("%d", ans);
  return 0;
}
