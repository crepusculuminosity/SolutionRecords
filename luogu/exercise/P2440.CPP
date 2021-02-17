#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int a[100005];

inline int read() {
  int x = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

bool check(int x) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] / x;
  }
  return ans >= k;
}

int main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  int l = 0, r = 100000001;
  int mid;

  while (l + 1 < r) {
    mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%d\n", l);
  return 0;
}