#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int fa[maxn], rnk[maxn], cnt[maxn];
int a, b;
void init() {
  for (int i = 1; i < maxn; i++)
    fa[i] = i, rnk[i] = 0, cnt[i] = 0;
}
int find(int x) {
  if (fa[x] == x)
    return x;
  return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
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
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  //freopen("data.in","r",stdin);
  // init();
  int kse = 1;
  while (1) {
    init();
    bool f = 1;
    int x = 0, y = 0;
    while (cin >> a >> b) {
      if (a == -1 && b == -1)
        return 0;
      if (a == 0 && b == 0)
        break;
      if (!cnt[a])
        ++cnt[a], ++x;
      if (!cnt[b])
        ++cnt[b], ++x;
      if (find(a) == find(b))
        f = 0;
      else {
        merge(a, b);
        ++y;
      }
    }
    cout << "Case " << kse++ << " is ";
    if (x == 0 && y == 0)
      cout << "a tree.\n";
    else if (f && y == x - 1)
      cout << "a tree.\n";
    else
      cout << "not a tree.\n";
  }
  return 0;
}