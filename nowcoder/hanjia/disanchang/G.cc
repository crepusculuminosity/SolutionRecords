#define Rf freopen("data.in", "r", stdin);
#define Wf wfopen("data.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
vector<int> vec[maxn];
int n, m;
typedef long long ll;
constexpr int maxn = 1e6 + 10;
struct pl {
  ll id, v;
} q[maxn];

int main() {
  Rf scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    q[i].id = i;
    scanf("%lld", &q[i].v);
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    ll tmp = max(q[a].v, q[b].v);
    q[a].v = tmp, q[b].v = tmp;
  }
  ll res = 0;
  for (int i = 1; i <= n; i++)
    res += q[i].v;
  printf("%lld", res);
  return 0;
}