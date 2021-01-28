#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

struct node {
  int left, right;
} tree[MAXN];

int n, ans;
void dfs(int x, int deep) {
  if (x == 0)
    return;
  ans = max(deep, ans);
  dfs(tree[x].left, deep + 1);
  dfs(tree[x].right, deep + 1);
}

int main() {
  // freopen("data.in","r",stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d %d", &tree[i].left, &tree[i].right);
  dfs(1, 1);
  printf("%d", ans);
  return 0;
}