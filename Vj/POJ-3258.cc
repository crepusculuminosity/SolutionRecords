#include <cstdio>
#include <algorithm>
using namespace std;
int a[500010];
int r, l, mid, ans;
int len, n, m;
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

bool check(int x) {
  int tot = 0;
  int now = 0;
  int i = 0;
  while (i <= n) {
    i++;
    if (a[i] - a[now] < x)
      tot++;
    else
      now = i;
  }
  return tot <= m;
}

int main() {

  len = read();
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a + 1, a + n + 1);
  a[n + 1] = len;
  l = 1;
  r = len;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  printf("%d\n", ans);
}