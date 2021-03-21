#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
struct node {
  int x, y, z;
  bool operator<(const node &oth) const { return z < oth.z; }
} a[50005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    a[i].x = read();
    a[i].y = read();
    a[i].z = read();
  }
  sort(a, a + n);
  double ans = 0;
  int cx = a[0].x, cy = a[0].y, cz = a[0].z;
  for (int i = 1; i < n; i++) {
    ans += sqrt((cx - a[i].x) * (cx - a[i].x) + (cy - a[i].y) * (cy - a[i].y) +
                (cz - a[i].z) * (cz - a[i].z));
    cx = a[i].x;
    cy = a[i].y;
    cz = a[i].z;
  }
  printf("%.3lf\n", ans);
  return 0;
}