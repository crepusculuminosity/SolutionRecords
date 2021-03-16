#include <bits/stdc++.h>
#define id(x) (lower_bound(b + 1, b + L + 1, x) - b)
#define rid(x) (b[x])
using namespace std;
const int MAXN = 2000005;

struct Node {
  int l, r, val;
} node[MAXN * 22];
int cnt, head[MAXN];

int N, M, L;
int a[MAXN];
int b[MAXN];

inline void build(Node &u, int l, int r) {
  u.val = 0;
  if (l == r)
    return;
  int mid = (l + r) >> 1;
  build(node[u.l = ++cnt], l, mid);
  build(node[u.r = ++cnt], mid + 1, r);
}

inline void insert(Node &u, Node c, int l, int r, int p, int val) {
  if (l == r) {
    u.val = val;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) {
    insert(node[u.l = ++cnt], node[c.l], l, mid, p, val);
    u.r = c.r;
  } else {
    insert(node[u.r = ++cnt], node[c.r], mid + 1, r, p, val);
    u.l = c.l;
  }
  u.val = min(node[u.l].val, node[u.r].val);
}

inline int query(Node u, int l, int r, int val) {
  if (l == r)
    return l;
  int mid = (l + r) >> 1;
  if (node[u.l].val < val)
    return query(node[u.l], l, mid, val);
  return query(node[u.r], mid + 1, r, val);
}

int main() {
  // freopen("data.in", "r", stdin);
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i)
    scanf("%d", &a[i]), b[++L] = a[i], b[++L] = a[i] + 1;
  b[++L] = 0;
  sort(b + 1, b + L + 1);
  L = unique(b + 1, b + L + 1) - b - 1;
  build(node[head[0] = ++cnt], 1, L);
  for (int i = 1; i <= N; ++i) {
    insert(node[head[i] = ++cnt], node[head[i - 1]], 1, L, id(a[i]), i);
  }
  for (int i = 1; i <= M; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", rid(query(node[head[r]], 1, L, l)));
  }
  return 0;
}
