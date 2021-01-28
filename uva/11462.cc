#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9')
    c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

inline void out(int x) {
  if (x > 9)
    out(x / 10);
  putchar('0' + x % 10);
}

int main() {
  // freopen("data.in","r",stdin);
  while (n = read()) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
      int x = read();
      ++a[x];
    }
    // for(int i=1; i<=1000; i++) {
    //   out(i); putchar('\n');
    // }
    int f = 1;
    // for(int i=1;i<=n;i++) printf("%d ",a[i]);
    for (int i = 1; i <= 100; i++) {
      for (int j = 1; j <= a[i]; j++) {
        if (!f)
          putchar(' ');
        f = 0;
        out(i);
      }
    }
    //  printf("\n");
    putchar('\n');
  }
  return 0;
}