#include <bits/stdc++.h>
using namespace std;
int t, n;
const int MAXN = 5e4 + 10;
int a[MAXN];
unordered_map<int, bool> m;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  // freopen("data.in","r",stdin);
  t = read();
  while (t--) {
    m.clear();
    n = read();
    for (int i = 1; i <= n; i++) {
      int x = read();
      if (!m[x]) {
        printf("%d ", x);
        m[x] = 1;
      }
    }
    putchar('\n');
  }
  return 0;
}