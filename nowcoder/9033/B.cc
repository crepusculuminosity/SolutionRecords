#include <stdio.h>
int main() {
  long long i, n, a[500001], cnt = 1;
  scanf("%lld", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (i = 1; i < n; i++) {
    if (a[i - 1] == 0 && a[i] == 1) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}