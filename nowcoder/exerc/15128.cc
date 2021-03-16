#include <bits/stdc++.h>
using namespace std;
bool vis[10];
int res[10];

void dfs(int s) {
  if (s == 9) {
    for (int i = 1; i <= 8; i++)
      printf("%d ", res[i]);
    puts("");
    return;
  }
  for (int i = 1; i <= 8; i++) {
    if (!vis[i]) {
      res[s] = i, vis[i] = 1;
      dfs(s + 1);
      res[s] = 0, vis[i] = 0;
    }
  }
}

int main() {
  // freopen("data.out","w",stdout);
  dfs(1);
  return 0;
}