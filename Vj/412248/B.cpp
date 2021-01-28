#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;

ll dfs(int x) {
  if (x <= k)
    return 1;
  if ((x - k) % 2 == 0)
    return dfs((x - k) / 2) + dfs((x + k) / 2);
  else
    return 1;
}

int main() {
  scanf("%lld%lld", &n, &k);
  printf("%lld", dfs(n));
  return 0;
}