#include <bits/stdc++.h>
using namespace std;
int fun(int m, int n) {
  if (m == 0 || n == 1)
    return 1;
  if (m < n)
    return fun(m, m);
  else
    return fun(m, n - 1) + fun(m - n, n);
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int _, m, n;
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &m, &n);
    printf("%d\n", fun(m, n));
  }

  return 0;
}