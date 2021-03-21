#include <bits/stdc++.h>
using namespace std;

int n, x, y;
stack<char> s;
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
  n = read();
  for (int i = 1; i <= n; i++) {
    char ch = getchar();
    if (ch == 'W') {
      y += 1;
      s.push(ch);
    }
    if (ch == 'A') {
      x -= 1;
      s.push(ch);
    }
    if (ch == 'S') {
      y -= 1;
      s.push(ch);
    }
    if (ch == 'D') {
      x += 1;
      s.push(ch);
    }

    if (ch == 'Z' && !s.empty()) {
      char c = s.top();
      if (c == 'A')
        x += 1;
      if (c == 'S')
        y += 1;
      if (c == 'W')
        y -= 1;
      if (c == 'D')
        x -= 1;
      s.pop();
    }
  }
  printf("%d %d\n", x, y);
  return 0;
}