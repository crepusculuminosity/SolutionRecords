#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int A[maxn], fa[maxn], rnk[maxn];
int n, m, a, b;

int find(int x) {
  if (x == fa[x])
    return x;
  else
    return fa[x] = find(fa[x]);
}

void init() {
  for (int i = 1; i <= n + 1; i++)
    fa[i] = i;
}

int main() {
  cin >> n >> m >> a >> b;
  init();
  for (int i = m; i >= 1; i--) {
    int l = (i * a + b) % n + 1, r = (i * b + a) % n + 1;
    if (l > r)
      swap(l, r);
    int x = find(l);
    while (x <= r) {
      A[x] = i;
      fa[x] = x + 1;
      x = find(x);
    }
  }
  for (int i = 1; i <= n; i++)
    cout << A[i] << " ";
  return 0;
}