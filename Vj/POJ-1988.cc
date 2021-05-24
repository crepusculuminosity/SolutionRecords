#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 3e4 + 10;

int fa[maxn], dis[maxn], sz[maxn];

int find(int x) {
  if (x == fa[x])
    return x;
  int root = find(fa[x]);
  dis[x] += dis[fa[x]];
  return fa[x] = root;
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  fa[y] = x;
  dis[y] += sz[x];
  sz[x] += sz[y];
}
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
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int n = read();
  for (int i = 1; i < maxn; i++)
    fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; i++) {
    char ch[5];
    //int x, y;
    scanf("%s", ch);
    if (ch[0] == 'M') {
      int x = read(), y = read();
      merge(x, y);
    } else {
      int x = read();
      printf("%d\n", sz[find(x)] - dis[x] - 1);
    }
  }
  return 0;
}