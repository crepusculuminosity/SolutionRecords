//#define TEST
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN];
int n, k;

void func(int n) {
  if (n > MAXN)
    return;
  else {
    a[n] = 1;
    func(2 * n + 1);
    func(3 * n + 1);
  }
}

int main() {
#ifdef TEST
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif

  string s;
  cin >> s;
  auto it = s.begin();
  while (*it != ',') {
    /* code */
    k = 10 * k + (*it) - '0';
    it++;
  }
  it++;
  while (it != s.end()) {
    /* code */
    n = n * 10 + (*it) - '0';
    it++;
  }
  a[k] = 1;
  func(k);
  if (a[n] == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}