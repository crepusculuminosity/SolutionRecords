#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e4 + 10;
int par[maxn], ran[maxn];

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
void init(int n) {
  for (int i = 1; i <= n; i++)
    par[i] = i, ran[i] = 0;
}

int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x == y)
    return;

  if (ran[x] < ran[y])
    par[x] = y;
  else {
    par[y] = x;
    if (ran[x] == ran[y])
      ++ran[x];
  }
}

bool same(int x, int y) { return find(x) == find(y); }

int main() {
  // freopen("data.in", "r", stdin);
  // int n,m;
  // cin>>n>>m;
  int n = read(), m = read();
  init(n);
  while (m--) {
    // int op,a,b;
    // cin>>op>>a>>b;
    int op = read(), a = read(), b = read();
    if (op == 1)
      merge(a, b);
    else {
      if (same(a, b))
        puts("Y");
      else
        puts("N");
    }
  }
  return 0;
}