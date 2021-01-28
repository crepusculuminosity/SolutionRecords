#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20000;
ll n;
ll a[maxn];
int level[maxn];
inline void update(int x) {
  while (x <= n) {
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

int main() {
  freopen("data.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    update(x);
  }
  for (int i = 0; i <= n; i++) {
    printf("%d\n", level[i]);
  }
  return 0;
}