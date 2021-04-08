#include <bits/stdc++.h>
using namespace std;

int a[15], n, vis[15];

void dfs(int cur) {
  if (cur == n + 1) {
    for (int i = 1; i <= n; i++)
      cout << a[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    a[cur] = i, vis[i] = 1;
    dfs(cur + 1);
    vis[i] = 0;
  }
}

int main() {
  cin >> n;
  dfs(1);
  return 0;
}