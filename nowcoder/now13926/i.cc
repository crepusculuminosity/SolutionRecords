#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
  ll n, k;
  cin >> n >> k;
  ll b = (ll)ceil((n + 0.0) / k);
  cout << n / b;
  return 0;
}
