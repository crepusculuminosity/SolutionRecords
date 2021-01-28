#include <bits/stdc++.h>
using namespace std;

int fun(int x) {
  if (x == 0)
    return 0;
  else
    return (x + 1) / 2 + fun(x / 4);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fun(n));
  return 0;
}