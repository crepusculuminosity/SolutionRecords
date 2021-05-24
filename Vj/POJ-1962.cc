#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 20000 + 10;
int fa[maxn], d[maxn];

int find(int x) {
  if (x == fa[x])
    return x;
  int root = find(fa[x]);
  d[x] += d[fa[x]];
  return fa[x] = root;
}
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch= getchar();
  return x;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int _ = read();
  while (_--) {
    int n = read();
    for (int i = 1; i <= n; i++)
      fa[i] = i, d[i] = 0;
    char ch[5];
    while (~scanf("%s", ch) && ch[0] != 'O') {
      if (ch[0] == 'E') {
        int u = read();
        find(u);
        printf("%d\n", d[u]);
      } else {
        int u = read(), v = read();
        fa[u] = v;
        d[u] = abs(u - v) % 1000;
      }
    }
  }
  return 0;
}