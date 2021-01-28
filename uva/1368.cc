#define RF freopen("data.in", "r", stdin);
#define WF freopen("data.out", "w", stdout);
#define mkp make_pair
#include <bits/stdc++.h>
using namespace std;
char a[55][1010];
int t, n, m;
int ans;

inline void ifind(int po) {
  int k[5] = {0, 0, 0, 0, 0};
  for (int i = 1; i <= m; i++) {
    if (a[i][po] == 'A')
      k[1]++;
    if (a[i][po] == 'C')
      k[2]++;
    if (a[i][po] == 'G')
      k[3]++;
    if (a[i][po] == 'T')
      k[4]++;
  }
  int maxn = k[1], cnt = 1, tmp = 0;
  for (int i = 1; i <= 4; i++) {
    tmp += k[i];
    if (k[i] > maxn) {
      maxn = k[i];
      cnt = i;
    }
  }
  switch (cnt) {
  case 1:
    putchar('A');
    break;
  case 2:
    putchar('C');
    break;
  case 3:
    putchar('G');
    break;
  case 4:
    putchar('T');
    break;
  }
  ans += tmp - k[cnt];
}

int main() {
  RF scanf("%d", &t);
  while (t--) {
    ans = 0;
    scanf("%d%d", &m, &n);
    getchar();
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = getchar();
      }
      getchar();
    }
    for (int i = 1; i <= n; i++)
      ifind(i);
    printf("\n%d\n", ans);
  }
  return 0;
}
