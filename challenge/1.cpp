#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  int a, n, b;
  while (t--) {
    scanf("%d%d%d", &a, &n, &b);
    double x = exp(exp(1) * log(a)) / n;
    printf("%.*lf\n", b, x);
  }
  return 0;
}