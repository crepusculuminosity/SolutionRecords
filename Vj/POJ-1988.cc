#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 3e4 + 10;
int fa[maxn], d[maxn];
int find(int x) {
  if (x == fa[x])
    return x;
  int root = find(fa[x]);
  d[fa[x]] += (d[x] + 1);
  return fa[x] = root;
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
  int n = read();
  char ch[5];
  for (int i = 1; i <= n; i++)
}