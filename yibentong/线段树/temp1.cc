//线段树 单点修改 区间查询

#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 5e5 + 10;
typedef long long ll;
ll ans;
int a[maxn];
struct node {
  int right, left;
  ll num;
} tree[maxn * 4];

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

inline void build(int l, int r, int index) {
  tree[index].left = l, tree[index].right = r;
  if (l == r)
    return;
  int mid = (r + l) / 2;
  build(l, mid, index << 1);
  build(mid + 1, r, index << 1 | 1);
}

inline void update(int index, int dis, int k) {
  tree[index].num += k;
  if (tree[index].left == tree[index].right)
    return;
  if (dis <= tree[index << 1].right)
    update(index << 1, dis, k);
  if (dis >= tree[index << 1 | 1].left)
    update(index << 1 | 1, dis, k);
}

inline void query(int index, int l, int r) {
  if (tree[index].left >= l && tree[index].right <= r) {
    ans += tree[index].num;
    return;
  }
  if (tree[index << 1].right >= l)
    query(index << 1, l, r);
  if (tree[index << 1 | 1].left <= r)
    query(index << 1 | 1, l, r);
}

ll add(int index) {
  if (tree[index].left == tree[index].right) {
    tree[index].num = a[tree[index].right];
    return tree[index].num;
  }
  tree[index].num = add(index << 1) + add(index << 1 | 1);
  return tree[index].num;
}

int main() {
  // freopen("data.in", "r", stdin);

  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  build(1, n, 1);
  add(1);
  while (m--) {
    int a = read(), b = read(), c = read();
    if (a == 1)
      update(1, b, c);
    else {
      ans = 0;
      query(1, b, c);
      printf("%d\n", ans);
    }
  }
  return 0;
}