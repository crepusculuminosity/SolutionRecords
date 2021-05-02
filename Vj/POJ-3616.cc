#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e6 + 10;
vector<int> G[maxn];
struct node {
  int l, r;
} q[maxn];
int w[maxn], d[maxn];
int n, m, r;

namespace IStream {
const int L = 1 << 15;
char buffer[L], *S, *T;
inline char _getChar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T)
      return EOF;
  }
  return *S++;
}

inline int _getInt() {
  char ch;
  int re = 0, f = 1;
  for (ch = _getChar(); ch < '0' || ch > '9'; ch = _getChar())
    ;
  while (ch >= '0' && ch <= '9') {
    re = (re << 1) + (re << 3) + (ch - '0');
    ch = _getChar();
  }
  return re;
}
} // namespace IStream
using IStream::_getInt;

int dfs(int x) {
  if (d[x])
    return d[x];
  int &res = d[x];
  res = w[x];
  int t = 0;
  for (int i = 0; i < G[x].size(); i++) {
    int a = dfs(G[x][i]);
    if (t < a)
      t = a;
  }
  return res += t;
}

int main() {  
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  // cout.tie(0);
  // cin >> n >> m >> r;
  n = _getInt(), m = _getInt(), r = _getInt();
  for (int i = 1; i <= m; i++) {
    int a = _getInt(), b = _getInt(), c = _getInt();
    q[i].l = a, q[i].r = b + r, w[i] = c;
  }
  // for (int i = 1; i <= m; i++)
  //  cout << q[i].l << ' ' << q[i].r << endl;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= m; j++) {
      if (i == j)
        continue;
      if (q[j].l >= q[i].r)
        G[i].push_back(j);
    }
  // int ans=0;
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    int r = dfs(i);
    if (ans < r)
      ans = r;
  }
  printf("%d",ans);
  return 0;
}