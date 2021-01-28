#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int val[MAXN];
vector<int> v[MAXN];
bool vis[MAXN];
int ans;

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void dfs(int u, int dep, int gl) {
  ans = max(ans, dep);
  int size = v[u].size();
  for (int i = 0; i < size; i++) {
    int uu = v[u][i];
    if (gcd(gl, val[uu]) > 1) {
      dfs(uu, dep + 1, gcd(gl, val[uu])); //加入
    } else
      dfs(uu, 1, val[uu]); //重新开始
  }
}

int main() {
  freopen("data.in", "r", stdin);
  int n = read();
  int root;
  for (int i = 1, x, y; i < n; i++) {
    x = read(), y = read();
    v[x].push_back(y);
    vis[y] = 1;
  }
  for (int i = 1; i <= n; i++) {
    val[i] = read();
    if (!vis[i])
      root = i;
  }
  dfs(root, 1, val[root]); //从根开始
  printf("%d\n", ans);
  return 0;
}