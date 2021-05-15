#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 32000;
int num[maxn], prime[maxn], cnt;

void init() {
  for (int i = 2; i < maxn; i++) {
    if (!num[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j])
        break;
    }
  }
}

int solve(int n) {
  int ans = 1;
  for (int i = 1; prime[i] * prime[i] <= n; i++) {
    int c = 1;
    while (n % prime[i] == 0) {
      ++c, n /= prime[i];
    }
    ans *= c;
  }
  if (n > 1)
    ans *= 2;
  return ans;
}

int main() {
  freopen("data.in","r",stdin);
  freopen("data.out","w",stdout);
  init();
  int _;
  scanf("%d", &_);
  while (_--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = -1, p;
    for (int i = l; i <= r; i++) {
      if (solve(i) > ans) {
        p = i, ans = solve(i);
      }
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, r, p,
           solve(p));
  }
  return 0;
}