#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;

struct edge {
  int from, to;
  double c, r;
} es[maxn * 2];

double d[maxn];
int n, m, s;
double v;

inline bool bellman_ford(int s, double v) {
  d[s] = v;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * m; j++) {
      edge e = es[j];
      if (d[e.to] < (d[e.from] - e.c) * e.r) {
        d[e.to] = (d[e.from] - e.c) * e.r; //判断正圈
        if (i == n)
          return 1;
      }
    }
  }
  return 0;
}

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  while (cin >> n >> m >> s >> v) {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= m; i++) {
      int a, b;
      cin >> a >> b;
      es[i].from = a, es[i].to = b, es[i + m].from = b, es[i + m].to = a;
      double x, y, z, w;
      cin >> es[i].r >> es[i].c >> es[i + m].r >> es[i + m].c;
    }
    if (bellman_ford(s, v))
      cout << "YES";
    else
      cout << "NO";
    cout << '\n';
  }
  return 0;
}