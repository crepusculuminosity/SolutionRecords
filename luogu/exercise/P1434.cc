#include <bits/stdc++.h>
using namespace std;

struct pos {
  int i, j, num;
};

struct functorcmp {
  bool operator()(pos &x, pos &y) { return x.num > y.num; }
};

int maxh;
priority_queue<pos, vector<pos>, functorcmp> q;
int a[105][105];
int dp[105][105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = 1;
      cin >> a[i][j];
      pos node;
      node.i = i;
      node.j = j;
      node.num = a[i][j];
      q.push(node);
    }
  }
  while (!q.empty()) {
    pos now = q.top();
    int i = now.i, j = now.j, num = now.num;
    q.pop();
    if (a[i - 1][j] < num)
      dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j]);
    if (a[i + 1][j] < num)
      dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j]);
    if (a[i][j + 1] < num)
      dp[i][j] = max(dp[i][j], 1 + dp[i][j + 1]);
    if (a[i][j - 1] < num)
      dp[i][j] = max(dp[i][j], 1 + dp[i][j - 1]);
    if (maxh < dp[i][j])
      maxh = dp[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      printf("%d ", dp[i][j]);
    printf("\n");
  }
  printf("%d\n", maxh);
  return 0;
}