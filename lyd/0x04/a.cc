#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int a[maxn];
int n, f;

int main() {
  cin >> n >> f;
  int r = -1;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    r = max(r, x);
    a[i] = a[i - 1] + x;
  }
}