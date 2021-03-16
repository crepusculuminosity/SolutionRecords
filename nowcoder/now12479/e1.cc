#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
int A[maxn];
int n, m, a, b;

int main() {
  // cin>>n>>m>>a>>b;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (int i = m; i >= 1; i--) {
    int l = (i * a + b) % n + 1, r = (i * b + a) % n + 1;
    if (l > r)
      swap(l, r);
    for (int j = l; j <= r; j++) {
      if (A[j])
        continue;
      A[j] = i;
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d\n", A[i]);
  return 0;
}