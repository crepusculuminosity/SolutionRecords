#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
ll f[N];

void fun() {
  for (int i = 4; i <= N; i++)
    f[i] = f[i - 2] + i - 3;
  for (int i = 4; i <= N; i++)
    f[i] += f[i - 1];
}

int main() {
  fun();
  int n;
  while (cin >> n && n >= 3)
    cout << f[n] << endl;
  return 0;
}
