#include <bits/stdc++.h>
using namespace std;
long long ans;
int n, a[305];

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    a[i] = read();
  sort(a, a + n + 1);
  int *head = a, *tail = a + n;
  while (head < tail) {
    ans += (*head - *tail) * (*head - *tail);
    head++;
    ans += (*head - *tail) * (*head - *tail);
    tail--;
  }
  cout << ans << endl;
  return 0;
}
