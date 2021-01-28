#include <bits/stdc++.h>
using namespace std;

struct guojia {
  int x, y;
  // bool operator> ( guojia q) {
  //    return y>q.y;
  //}
} a[130];
int main() {
  // freopen("data.in","r",stdin);
  int n;
  scanf("%d", &n);
  int l = pow(2, n);
  for (int i = 1; i <= l; i++) {
    a[i].x = i;
    scanf("%d", &a[i].y);
  }
  while (l > 2) {
    for (int i = 1, j = 1; i <= l; i += 2, j++) {
      if (a[i].y > a[i + 1].y)
        a[j].x = a[i].x, a[j].y = a[i].y;
      else
        a[j].x = a[i + 1].x, a[j].y = a[i + 1].y;
    }
    l /= 2;
  }
  if (a[1].y < a[2].y)
    printf("%d\n", a[1].x);
  else
    printf("%d\n", a[2].x);
  return 0;
}