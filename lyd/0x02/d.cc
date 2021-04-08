#include <bits/stdc++.h>
using namespace std;

int a[15], b[15];
void pre() {
  b[1] = 1;
  for (int i = 1; i <= 14; i++)
    b[i] = 2 * b[i - 1] + 1;
}

int main() {
  memset(a, 0x3f, sizeof(a));
  pre();
  a[1] = 1;
  cout << a[1] << endl;
  for (int i = 2; i <= 12; i++) {
    for (int j = 1; j < i; j++)
      a[i] = min(a[i], 2 * a[j] + b[i - j]);
    cout << a[i] << endl;
  }
  return 0;
}