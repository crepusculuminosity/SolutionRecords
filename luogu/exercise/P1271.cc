#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
int a[MAXN];

void _swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void _qSort(int l, int r) {
  if (l >= r)
    return;
  int mid = a[(l + r) / 2];

  int p = l, q = r;

  do {
    while (a[p] < mid)
      p++;
    while (a[q] > mid)
      q--;

    if (p <= q) {
      _swap(a[p], a[q]);
      p++;
      q--;
    }
  } while (p <= q);

  if (l < q)
    _qSort(l, q);
  if (p < r)
    _qSort(p, r);
}

int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  _qSort(1, n);

  for (int i = 1; i <= n; i++)
    printf("%d ", a[i]);
  return 0;
}