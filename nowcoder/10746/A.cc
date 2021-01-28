#include <bits/stdc++.h>
using namespace std;

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int a, x;
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  // int _; scanf("%d",&_);
  int _ = read();
  while (_--) {
    int ans = 0;
    // scanf("%d%d",&a,&x);
    a = read();
    x = read();
    for (int i = 1; i <= x; i++) {
      if ((a & i) == 0) {
        ans++;
        cout << i << endl;
      }
    }
    // printf("%d\n",ans);
    printf("\n", ans);
  }
  return 0;
}