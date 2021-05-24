#include <cstdio>
using namespace std;
const int maxn = 100000 + 10;
int a[maxn], n, m;

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  }
  return x * f;
}

bool check(int x) {
  int now=0,tot=0;
  for(int i=1;i<=n;i++) {
    while
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    a[i] = a[i - 1] + x;
  }
  int l = 1, r = maxn;
  while (l < r - 1) {
    int mid = l + r >> 1;
  }
}