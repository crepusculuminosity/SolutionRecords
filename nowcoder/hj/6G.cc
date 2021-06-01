#include <bits/stdc++.h>
using namespace std;
int n, x;
struct node {
  int a, b;
  bool operator<(const node &x) const { return x.a * b + x.b > a * x.b + b; }
} q[30];
using lll = __int128;
inline void print(lll x) {
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + 48);
}
int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++)
    cin >> q[i].a >> q[i].b;
  sort(q + 1, q + 1 + n);
  lll ans = x;
  for (int i = 1; i <= n; i++)
    ans = ans * q[i].a + q[i].b;
  print(ans);
  return 0;
}