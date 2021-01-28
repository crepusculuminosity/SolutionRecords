#include <bits/stdc++.h>
using namespace std;

int trans(int x) {
  int res, i = 1, s = 1, cnt = 0;
  while (x) {
    res = x % 2;
    cnt += res;
    x /= 2;
  }
  return cnt;
}
int main() {
  int n;
  cin >> n;
  if (trans(n) > 3)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}