#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[2000005];

int main() {
  // freopen("data.in","r",stdin);
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }

    sort(a + 1, a + n + 1); // 排序

    for (int i = 1; i < n; i++) {
      printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
  }
  return 0;
}