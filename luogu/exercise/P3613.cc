#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
map<ll, int> m;

int p, k;

ll i, j;
const ll M = 1e6;

int main() {
  cin >> n >> q;
  while (q--) {
    cin >> p >> i >> j;
    if (p == 1) {
      cin >> k;
      m[i * M + j] = k;
    } else
      cout << m[i * M + j] << endl;
  }
  return 0;
}