#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (x)
      s.insert(x);
  }
  printf("%d", s.size());
  return 0;
}