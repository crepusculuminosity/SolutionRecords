#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
ll a[maxn];

int main() {
  ll mod = 1;
  for (int i = 1; i <= 9; i++)
    mod *= 10;
  int n;
  cin >> n;
  a[1] = 1, a[2] = 2;
  for (int i = 3; i <= n; i++) {
    if (i & 1)
      a[i] = a[i - 1];
    else
      a[i] = (a[i >> 1] + a[i - 1]) % mod;
  }
  cout << a[n];
  return 0;
}