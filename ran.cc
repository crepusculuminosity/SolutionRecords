#include <bits/stdc++.h>
#define u32 unsigned
#define i64 long long
#define u64 unsigned long long
#define f80 long double
using namespace std;
#define MAXN 55

clock_t __t_bg, __t_ed;

int N, M, all;
int fa[MAXN];
typedef vector<int> vc;
vc v;
map<vc, double> mp;

int find(int x) { return fa[x] > 0 ? fa[x] = find(fa[x]) : x; }
inline void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y)
    fa[x] < fa[y] ? swap(x, y), 1 : 1, fa[y] += fa[x], fa[x] = y;
}

double DP(vc c) {
  if (mp.count(c))
    return mp[c];
  int s(c.size()), ts(0);
  if (s == 1)
    return mp[c] = 0;
  for ( int i = 0; i < s; ++i)
    ts += c[i] * (c[i] - 1) / 2;
  double p(1. * all / (all - ts));
  for ( int i = 1; i < s; ++i)
    for ( int j = 0; j < i; ++j) {
      vc t(c);
      t[j] += t[i], swap(t[i], t[s - 1]), t.pop_back(),
          sort(t.begin(), t.end());
      p += 1. * c[i] * c[j] / (all - ts) * DP(t);
    }
  return mp[c] = p;
}

signed main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  __t_bg = clock();
  while (~scanf("%d%d", &N, &M)) {
    memset(fa, -1, sizeof fa), all = N * (N - 1) / 2;
    for ( int i = 1, x, y; i <= M; ++i)
      scanf("%d%d", &x, &y), merge(x, y);
    v.clear();
    for ( int i = 1; i <= N; ++i)
      if (fa[i] < 0)
        v.push_back(-fa[i]);
    printf("%.6lf\n", DP(v));
  }
  __t_ed = clock(),
  fprintf(stderr, "time: %.5lfs\n", double(__t_ed - __t_bg) / CLOCKS_PER_SEC);
  return 0;
}
