#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1100;

double p[maxn], f[maxn];
int n, k, m;

int main() {
  // freopen("data.in","r",stdin);
  int t, kase = 1;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; i++)
      scanf("%lf", p + i);
    memset(f, 0, sizeof(f));
    f[1] = p[0];
    for (int i = 2; i <= m; i++) {
      for (int j = 0; j < n; j++)
        f[i] += p[j] * pow(f[i - 1], j);
    }
    printf("Case #%d: %.7lf\n", kase++, pow(f[m], k));
  }
  return 0;
}