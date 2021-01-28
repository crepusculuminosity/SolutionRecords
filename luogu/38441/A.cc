#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    /* code */
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
struct Person {
  int c, k, t;
  bool operator<(const Person &a) {
    if (k * t < a.k * a.t)
      return 0;
    if (k * t > a.k * a.t)
      return 1;
    else if (k * t == a.k * a.t) {
      if (t > a.t)
        return 1;
      if (t < a.t)
        return 0;
      else {
        return c <= a.c;
      }
    }
  }
} q[MAXN];

int main() {
  freopen("data.in", "r", stdin);

  n = read();
  // printf("%d\n",n);
  for (int i = 1; i <= n; i++)
    q[i].c = i, q[i].t = read(), q[i].k = read();

  sort(q + 1, q + 1 + n);
  for (int i = 1; i <= n; i++)
    printf("%d ", q[i].c);
  return 0;
}