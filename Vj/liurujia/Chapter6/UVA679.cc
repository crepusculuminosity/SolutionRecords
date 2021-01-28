#include <bits/stdc++.h>
using namespace std;

int k, n, d;
int main() {
  // freopen("data.in","r",stdin);

  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &d, &n);
    k = 1;

    // if(k>m) break;
    for (int i = 0; i < d - 1; i++) {
      if (n % 2) {
        k *= 2;
        n = (n + 1) >> 1;
      } else {
        k = 2 * k + 1;
        n >>= 1;
      }
    }
    printf("%d\n", k);
  }
}