#include <bits/stdc++.h>
using namespace std;
#define lb(x) ((x) & (-x))
constexpr int maxn = 5e5 + 10;
typedef long long ll;
ll tr[maxn];
int n;

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

inline void update(int x, int k) {
  while (x <= n) {
    tr[x] += k;
    x += lb(x);
  }
}

inline ll query(int x) {
  ll res = 0;
  while (x) {
    res += tr[x];
    x -= lb(x);
  }
  return res;
}

int main() {
  //freopen("data.in", "r", stdin);
  n = read();
  int q = read();
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = read();
    update(x, 1);
    sum += i - query(x);
  }
  // int q = read();
  int ans = sum % 2;
  while (q--) {
    int op = read(), x = read(), y = read();
    if (op == 1)
      ans = (ans + 1) % 2;
    else if (op == 2) {
      ll t = 1LL*(y - x) * (y - x + 1) >> 1;
      ans = (ans + (t % 2)) % 2;
    } else {
      int k = read();
      ans = (ans + 1LL*k * (y - x) % 2) % 2;
    }
    printf("%d\n",ans);
  }
  return 0;
}
