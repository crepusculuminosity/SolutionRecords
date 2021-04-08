#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int num[maxn], l[maxn], r[maxn];
int st[maxn][30];
int n, m;
int cnt;

void _clear() {
  cnt = 0;
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  memset(st, 0, sizeof(st));
  memset(num, 0, sizeof(num));
}

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

inline void stinit() {
  for (int i = 1; i <= cnt; i++)
    st[i][0] = 1 + r[i] - l[i];
  for (int j = 1; j <= 19; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++)
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

inline int query(int x, int y) {
  if (num[x] == num[y])
    return y - x + 1;
  int ans = 0;
  if (num[x] + 1 <= num[y] - 1) {
    int L = num[x] + 1, R = num[y] - 1, k = 0;
    while (1 << (k + 1) <= R - L + 1)
      k++;
    ans = max(st[L][k], st[R - (1 << k) + 1][k]);
  }
  ans = max(ans, max(r[num[x]] - x + 1, y - l[num[y]] + 1));
  return ans;
}

int main() {
  freopen("data.in", "r", stdin);
  while (1) {
    _clear();
    n = read();
    if (!n)
      break;
    m = read();
    int tmp = -maxn;
    for (int i = 1; i <= n; i++) {
      int x = read();
      cout << x << " ";
      if (x != tmp)
        r[cnt] = i - 1, l[++cnt] = i, tmp = x;
      num[i] = cnt;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
      cout << num[i] << " " << l[i] << " " << r[i] << endl;
    /*stinit();
while (m--) {
  int l = read(), r = read();
  printf("%d\n", query(l, r));
}
}*/
  }
  return 0;
}