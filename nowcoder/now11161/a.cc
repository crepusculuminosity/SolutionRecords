#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 100005
#define M 50

using namespace std;

char a[N], b[M], st[M];
int ans = 0, n, m, len;

bool bz[N];

void dfs(int x) {
  if (x > m) {
    len = 0;
    for (int i = 1; i <= m; i++)
      if (bz[i])
        st[++len] = b[i];
    for (int i = 1; i <= len / 2; i++)
      if (st[i] != st[len - i + 1])
        return;
    int i = 1, j = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i] == st[j])
        j++;
      if (j > len)
        break;
    }
    if (j <= len)
      return;
    ans = max(ans, len);
    return;
  }
  bz[x] = true;
  dfs(x + 1);
  bz[x] = false;
  dfs(x + 1);
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  scanf("%s", a + 1);
  n = strlen(a + 1);
  scanf("%s", b + 1);
  m = strlen(b + 1);
  dfs(1);
  printf("%d", ans);
}