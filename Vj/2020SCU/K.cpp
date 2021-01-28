#include <bits/stdc++.h>
using namespace std;

bool num[10000001];
int prime[100000], cnt;

void _getPri(int n) {
  // memset(num,1,sizeof(num));
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
  int n;
  scanf("%d", &n);
  _getPri(n);
  for (int i = 2; i <= n / 2; i++) {
    if (!num[i] && !num[n - i]) {
      printf("%d %d", i, n - i);
      break;
    }
  }
  printf("\n");
  return 0;
}