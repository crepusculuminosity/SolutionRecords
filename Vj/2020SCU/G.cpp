#include <bits/stdc++.h>

char map[9][9];
int vis[50], n, k, ans;

void dfs(int m, int k) {
  if (k == 0) {
    ans++;
    return;
  }
  for (int i = m; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (map[i][j] == '.' || vis[j] == 1)
        continue;
      vis[j] = 1;
      dfs(i + 1, k - 1);
      vis[j] = 0;
    }
}

int main() {
  while (~scanf("%d%d", &n, &k) && n != -1) {
    for (int i = 0; i < n; i++)
      scanf("%s", &map[i]);
    memset(vis, 0, sizeof(vis));
    ans = 0;
    dfs(0, k);
    printf("%d\n", ans);
  }
  return 0;
}