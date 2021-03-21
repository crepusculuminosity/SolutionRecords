#include <bits/stdc++.h>
using namespace std;

int n, ans, x;

priority_queue<int, vector<int>, greater<int>> q;

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

inline void out(int x) {
  if (x > 9)
    out(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    x = read();
    q.push(x);
  }
  while (q.size() > 1) {
    /* code */
    int a = q.top();
    q.pop();
    int b = q.top();
    q.pop();
    q.push(a + b);
    ans += a + b;
  }
  // out(ans);
  printf("%d\n", ans);
  return 0;
}