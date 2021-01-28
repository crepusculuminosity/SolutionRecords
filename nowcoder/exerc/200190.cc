#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 32010;
ll n;
ll a[maxn];
int level[maxn];
ll tmp[maxn];
inline void update(int x) {
  while (x <= maxn) {
    a[x]++;
    x += lb(x);
  }
}

inline ll query(int x) {
  ll res = 0;
  while (x >= 1) {
    res += a[x];
    x -= lb(x);
  }
  return res;
}

inline void init() {
  for (int i = 1; i <= maxn; i++) {
    a[i] += tmp[i];
    if (i + lb(i) <= maxn)
      a[i + lb(i)] += a[i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ++x;
    level[query(x)]++;
    update(x);
  }
  for (int i = 0; i < n; i++)
    printf("%d\n", level[i]);
  return 0;
}