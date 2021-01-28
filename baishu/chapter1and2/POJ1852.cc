#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

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

const int MAXN = 1e6 + 5;
int n, l;
int a[MAXN];
int maxn, minn;
int main() {
  freopen("data.in", "r", stdin);
  // freopen("data.out","w",stdout);
  int _;
  _ = read();
  // scanf("%d",&_);
  while (_--) {
    /* code */
    minn = maxn = 0;
    memset(a, 0, sizeof(a));
    scanf("%d%d", &l, &n);
    for (int i = 1; i <= n; i++) {
      // scanf("%d",a+i);
      a[i] = read();
      minn = max(minn, min(a[i], l - a[i]));
      maxn = max(maxn, max(a[i], l - a[i]));
    }
    printf("%d %d\n", minn, maxn);
  }
  return 0;
}