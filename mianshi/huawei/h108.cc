#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a, b;
  cin >> a >> b;
  cout << a / __gcd(a, b) * b;
  return 0;
}