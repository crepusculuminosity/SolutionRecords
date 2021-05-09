#include <bits/stdc++.h>
using namespace std;
int n, m;
constexpr int maxn = 1e5 + 10;
vector<int> G[maxn];
int dp[maxn];

inline bool read(int& x) {
  x=0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch=getchar();
  while(ch >= '0' && ch <= '9') x=(x << 1) + (x << 3)+ch-48,ch=getchar();
  return 1;
}

int dfs(int u) {

  if (dp[u])
    return dp[u];
  if (G[u].size() == 0)
    return 1;
  int &res = dp[u]=0;
  int k = G[u].size();
  /*vector<int> c;
  for (int i = 0; i < k; i++)
    c.push_back(dfs(G[u][i]));
  sort(c.begin(), c.end());*/
  //'/memset(d, 0, sizeof(d));
  //int d[maxn];
  vector<int> d(k);
  for (int i = 0; i < k; i++)
    d[i] = dfs(G[u][i]);
  sort(d.begin(), d.end());
 
  int tot = (k * m - 1) / 100 + 1;
  for (int i = 0; i < tot; i++)
    res += d[i];
  return res;
}

int main() {

  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  
  while (read(n)&&read(m) && n) {
    for (int i = 0; i <= n; i++)
      G[i].clear();
    memset(dp, 0, sizeof(dp));
   // memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
      int x;
      read(x);
      G[x].push_back(i);
    }
    printf("%d\n",dfs(0));

  }
  return 0;
}