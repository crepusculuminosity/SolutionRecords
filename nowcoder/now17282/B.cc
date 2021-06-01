#include <bits/stdc++.h>
using namespace std;
int n;
int a[60];
int work(int *a) {
  int tot = 0;
  for (int i = 1; i <= n - 1; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] > a[j])
        swap(a[i], a[j]), ++tot;
  return tot;
}


int main() {
  freopen("data.out","w",stdout);
  srand((unsigned)time(NULL));
  for (int T = 1; T <= 100; T++) {
    int n = rand() % 50 + 1;
    for (int i = 1; i <= n; i++) {
      a[i] = rand() % 107 + 1;
      cout << a[i] << ' ';
    }
    cout << '\n';
    cout << work(a) << '\n';
    cout << '\n';
  }
  return 0;
}