#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 10;
int fa[maxn], rnk[maxn];
int vis[maxn];
int f;

void init() {
  f = 1;
  for (int i = 1; i < maxn; i++)
    fa[i] = i, rnk[i] = 0;
}

int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    f = 0;
  return;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
}

int main() {
  freopen("data.in", "r", stdin);
  int m, n;
  init();
  while (cin >> n >> m && ~n) {
    if (n == 0 && m == 0) {
      if(f==0) cout<<"No"<<endl;
      else {
        set<int> s;
        for(int i=1;i<maxn&&vis[i];i++)
          cout<<i<<' '<<find(i)<<endl;
      }
      init(); f=1;
      continue;
    }
    vis[n] = 1;
    vis[m] = 1;
    merge(n, m);
  }
  return 0;
}