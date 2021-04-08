#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000 + 10;
bool f;
int fa[maxn], rnk[maxn];
int vis[maxn];
void init() {
  f = 1;
  for (int i = 1; i < maxn; i++)
    fa[i] = i, rnk[i] = 0;
}
int find(int x) {
  while (fa[x] != x)
    x = fa[x];
  return x;
} //递归可能会爆栈
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    f = 0;
    return;
  }
  // fa[x]=y;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
}
int main() {
  // freopen("data.in", "r", stdin);
  int m, n;
  set<int> s;
  while (cin >> n >> m && ~n) {
    init();
    int sum = 1;
    if (n == 0 && m == 0) {
      cout << "Yes" << '\n';
      continue;
    }
    if (n == -1 && m == -1)
      break;
    // s.insert(n),s.insert(m);
    m = find(m), n = find(n);
    if (m == n)
      f = 0;
    else
      merge(n, m);
    vis[n] = vis[m] = 1;
    cout << find(m) << ' ' << find(n) << endl;
    while (1) {
      cin >> n >> m;
      if (n == 0 && m == 0)
        break;
      n = find(n), m = find(m);
      if (n == m)
        f = 0;
      else
        merge(n, m), vis[n] = vis[m] = 1;
    }
    /*for(int i = 1; i < maxn; i++)
  if(vis[i]) cout<<find(i)<<' ';
cout<<endl;*/
    if (f) {
      for (int i = 1; i < maxn; i++)
        if (vis[i])
          s.insert(find(i));
      if (s.size() == 2)
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    } else
      cout << "No" << '\n';
  }
  return 0;
}