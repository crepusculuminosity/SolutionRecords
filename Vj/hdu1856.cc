#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e7 + 10;
int fa[maxn], rnk[maxn];
int ans;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline void init() {
  ans=1;//我真是sb，如果全部x==y，那么不会进行合并操作，只能输出1
  for (int i = 1; i < maxn; i++)
    fa[i] = i, rnk[i] = 1;
}
inline int find(int x) {
  if(x==fa[x]) return x;
  return fa[x] = find(fa[x]);
}
inline void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return;
  if (rnk[x] < rnk[y]) {
    fa[x] = y, rnk[y] += rnk[x];
    ans = max(ans, rnk[y]);
  } else {
    fa[y] = x, rnk[x] += rnk[y];
    ans = max(ans, rnk[x]);
  }
}
int main() {
  //freopen("data.in", "r", stdin);
  int n;
  while (~scanf("%d", &n)) {
    init();
    for (int i = 1; i <= n; i++) {
      int x = read(), y = read();
      merge(x, y);
    }
    printf("%d\n", ans);
  }
  return 0;
}