#include <bits/stdc++.h>
using namespace std;
char a[30][30];
int n;

bool check1() {
  for (int i = 1; i <= n; i++) {
    int a = 0, b = 0;
    for (int j = 1; j <= n; j++) {
      if (a[1][j] == 'W')
        ++a;
      else
        ++b;
    }
    if (a != b)
      return 0;
    for (int j = 1; j <= n - 2; j++) {
      if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2])
        return 0;
    }
  }
  return 1;
}
bool check2() {
  for (int i = 1; i <= n; i++) {
    int a = 0, b = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j][i] == 'W')
        ++a;
      else
        ++b;
    }
    if (a != b)
      return 0;
    for (int j = 1; j <= n; j++)
      if (a[j][i] == a[j + 1][i] && a[j + 1][i] == a[j + 2][i])
        return 0;
  }
  return 1;
}

int main() {
  bool f = 1;
  freopen("data.in", "r", stdin);
  cin >> n;
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      a[i][j] = getchar();
    getchar();
  }
  if (check2() && check1())
    cout << "1";
  else
    cout << "0";
  return 0;
}