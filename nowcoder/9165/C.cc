#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[21] = {0, 0, 1};

ll jiecheng(int n) {
  ll res = 1;
  for (int i = n; i > 0; i--) {
    res = res * i;
  }
  return res;
}

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int t;
  cin >> t;
  for (int i = 3; i <= 20; i++) {
    a[i] = a[i - 1] * (i - 1) + a[i - 2] * (i - 1);
  }
  while (t--) {
    /* code */
    int n;
    cin >> n;
    ll x = jiecheng(n);
    ll g = gcd(x, a[n]);

    cout << a[n] / g << "/" << x / g << endl;
  }
  return 0;
}