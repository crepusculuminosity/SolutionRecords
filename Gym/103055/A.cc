#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll x;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll a = 0, b = 0;
  for (int i = 1; i <= 5; i++) {
    cin >> x;
    a += x;
  }
  for (int i = 1; i <= 5; i++) {
    cin >> x;
    b += x;
  }
  if (a >= b)
    cout << "Blue\n";
  else
    cout << "Red\n";
  return 0;
}