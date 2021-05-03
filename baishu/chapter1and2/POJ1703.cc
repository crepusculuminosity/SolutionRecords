#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
const int maxn = 100000 + 10;
int fa[maxn * 2], rnk[maxn * 2];
inline int read() {
  int x=0;
  char ch=getchar();
  while(ch < '0' || ch > '9') ch=getchar();
  while(ch>='0' && ch <= '9') x=(x<< 1) + (x << 3)+ch-48, ch = getchar();
  return x;
}
int find(int x) {
  if (x == fa[x])
    return x;
  return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return 0;
  if (rnk[x] < rnk[y])
    fa[x] = y;
  else {
    fa[y] = x;
    if (rnk[x] == rnk[y])
      ++rnk[x];
  }
  return 1;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);

  //ios::sync_with_stdio(false);
  //cin.tie(0), cout.tie(0);
  int _=read();
  //cin >> _;
  while (_--) {
    //cin >> n >> m;
    n=read(),m=read();
    for (int i = 1; i <= n * 2; i++)
      fa[i] = i, rnk[i] = 0;
    for (int i = 1; i <= m; i++) {
      int u, v;
      char ch=getchar(); getchar();
      //cin >> ch >> u >> v;
      u=read(),v= read();
      if (ch == 'D') {
        merge(u, v + n);
        merge(u + n, v);
      } else {
        if(find(u)==find(v)||find(v)==find(u))
          //cout<<"In the same gang.\n";
          puts("In the same gang.");
        else if(find(v)==find(u+n)||find(u)==find(v+n))
          //cout<<"In different gangs.\n";
          puts("In different gangs.");
        else puts("Not sure yet.");
      }
    }
  }
  return 0;
}