#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int minn = 1000005;
char c[100005];

int sum;
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  if (n & 1)
    printf("-1\n");
  else {
    for (int i = 1; i <= n; i++) {
      char ch = getchar();
      if (ch == ')')
        a[i] = a[i - 1] - 1;
      else
        a[i] = a[i - 1] + 1;
      minn = min(minn, a[i]);
    }
    minn = -minn;
    int x = (minn + 1) / 2;
    int res = x + (a[n] + 2 * x) / 2;
    printf("%d\n", res);
  }

  return 0;
}