#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 100001;
int a[maxn], vis[maxn];
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
  int _ = read();
  while (_--) {
    int n = read();
    for (int i = 1; i <= n; i++) 
      a[i] = read();
    // if (n == 1)
    //  puts("1");
    // else {
    int m;
    for (m = 1;; m++) {
      bool f = 1;
      memset(vis, 0, sizeof(vis));
      for (int i = 1; i <= n; i++) {
        if (vis[a[i] % m]) {
          f = 0;
          break;
        }
        vis[a[i] % m] = 1;
      }
      if (f)
        break;
    }
    printf("%d\n", m);
  }
  return 0;
}
