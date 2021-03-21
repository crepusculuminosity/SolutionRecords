#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define eps 1e-16

ld a[1001][1001], tmp[1001];
int n;

void swap(int x, int y) {
  for (int i = 1; i <= n + 1; i++)
    tmp[i] = a[x][i];
  for (int i = 1; i <= n + 1; i++)
    a[x][i] = a[y][i];
  for (int i = 1; i <= n + 1; i++)
    a[y][i] = tmp[i];
}

bool Agreater(int k, int x, int y) {
  if (fabs(fabs(a[x][k]) - fabs(a[y][k])) > eps)
    return fabs(a[x][k]) > fabs(a[y][k]);
  for (int i = k + 1; i <= n; i++) {
    if (fabs(fabs(a[x][i]) - fabs(a[y][i])) > eps)
      return fabs(a[x][i]) < fabs(a[y][i]);
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n + 1; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    int r = i;
    for (int j = i + 1; j <= n; j++) {
      if (Agreater(i, j, r))
        r = j;
    }
    if (r != i)
      swap(r, i);
    ld k = a[i][i];
    if (fabs(k) < eps)
      continue;
    for (int j = i; j <= n + 1; j++)
      a[i][j] /= k;
    for (int j = i + 1; j <= n; j++) {
      ld k = a[j][i];
      for (int l = i; l <= n + 1; l++)
        a[j][l] -= a[i][l] * k;
    }
  }
  for (int i = n; i > 0; i--) {
    if (a[i][i] == 0)
      continue;
    for (int j = i - 1; j > 0; j--) {
      a[j][n + 1] -= a[j][i] * a[i][n + 1];
      a[j][i] = 0;
    }
  }
  bool noans = 0, mulans = 0;
  for (int i = 1; i <= n; i++) {
    if (fabs(a[i][i]) < eps && fabs(a[i][n + 1]) > eps)
      noans = 1;
    if (fabs(a[i][i]) < eps && fabs(a[i][n + 1]) < eps)
      mulans = 1;
  }
  if (noans) {
    cout << "No Solution" << endl;
    exit(0);
  }
  if (mulans) {
    cout << "Multiple Solution" << endl;
    exit(0);
  }
  for (int i = 1; i <= n; i++) {
    if (fabs(a[i][n + 1]) < eps)
      cout << 0 << " ";
    else
      cout << fixed << setprecision(2) << a[i][n + 1] << " ";
  }
  return 0;
}