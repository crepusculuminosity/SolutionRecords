#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 70;
int n, start[MAXN], finish[MAXN], kase;
//假了
ll f(int *p, int i, int end) {
  if (i == 0)
    return 0;
  if (p[i] == end)
    return f(p, i - 1, end);
  return f(p, i - 1, 6 - p[i] - end) + (1LL << (i - 1));
}

int main() {
  //  freopen("data.in","r",stdin);

  while (~scanf("%d", &n) && n) {
    for (int i = 1; i <= n; i++)
      scanf("%d", start + i);
    for (int i = 1; i <= n; i++)
      scanf("%d", finish + i);
    int k = n;
    while (k >= 1 && start[k] == finish[k])
      k--;

    ll ans = 0;
    if (k >= 1) {
      int o = 6 - start[k] - finish[k];
      ans = f(start, k - 1, o) + f(finish, k - 1, o) + 1;
    }
    printf("Case %d: %lld\n", ++kase, ans);
  }
  return 0;
}