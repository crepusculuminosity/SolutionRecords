#define lb(x) ((x) & (-x))
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 3e4 + 10;
ll m, n, a[maxn], s[maxn], tr[maxn * 2];

int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = a[i];
  }
  sort(s + 1, s + 1 + n);
  m = unique(s + 1, s + 1 + n) - s - 1;
}