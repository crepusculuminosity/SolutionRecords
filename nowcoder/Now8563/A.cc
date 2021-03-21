#include <bits/stdc++.h>
using namespace std;

int n, k, x;

typedef long long ll;

priority_queue<int> q;

inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  ll sum = 0;
  n = read();
  k = read();
  for (int i = 1; i <= n; i++) {
    cin >> x;
    sum += x;
    q.push(x);
  }

  while (!q.empty() && k) {
    x = q.top();
    if (x % 2 == 0) {
      x /= 2;
      q.pop();
      q.push(x);
      sum -= x;
      k--;
    } else {
      q.pop();
    }
  }

  cout << sum << endl;
  return 0;
}