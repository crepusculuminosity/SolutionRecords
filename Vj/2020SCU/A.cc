#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int main() {
  cin >> n;
  ll ans;
  if (n & 1)
    ans = (-n - 1) / 2;
  else
    ans = n / 2;
  cout << ans << endl;
  return 0;
}