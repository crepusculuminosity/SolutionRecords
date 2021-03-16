#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
  scanf("%d", &n);
  for (int l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l); // 区间最右边
    ans += (n / l) * (r - l + 1);
  }
  printf("%d\n", ans);
}