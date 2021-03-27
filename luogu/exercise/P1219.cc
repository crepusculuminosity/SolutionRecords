#include <bits/stdc++.h>
using namespace std;

int ans[14];
int n;
int vis[14];
void dfs(int cur) {
  if (cur == n) {
    for (int i = 1; i <= n; i++)
      cout << ans[i] << ' ';
    cout << endl;
    return;
  }
  for (int i = 1; i <= n && !vis[i]; i++) {
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ans[1] = i, vis[i] = 1;
    dfs(1);
  }
}