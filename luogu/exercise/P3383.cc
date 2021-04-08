#include <bits/stdc++.h>
using namespace std;

bool num[100000001];
int prime[6000010], cnt;

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

void solve(int n) {
  num[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (num[i] == 0)
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
    /*for(int j=2;i*j<=n;j++)
    num[i*j]=0; */
  }
  return;
}

int main() {
  int m, q;
  m = read();
  q = read();
  solve(m);
  while (q--) {
    int k = read();
    printf("%d\n", prime[k]);
  }
  return 0;
}