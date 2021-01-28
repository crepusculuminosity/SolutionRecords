#include <bits/stdc++.h>

const int MAXD = 20;
int s[1 << MAXD];

int main() {
  int d, i;
  while (scanf("%d%d", &d, &i) == 2 && d > 0) {
    int k = 1;
    for (int j = 0; j < d - 1; j++) {
      if (i % 2) {
        k *= 2;
        i = (1 + i) >> 1;
      } else {
        k = (k << 1) + 1;
        i >>= 1;
      }
    }
    printf("%d\n", k);
  }
  return 0;
}