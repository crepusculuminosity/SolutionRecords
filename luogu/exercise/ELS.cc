#include <bits/stdc++.h>
using namespace std;

bool num[1000001];
int prime[6000010], cnt;

void solve(int n) {
  // memset(num,1,sizeof(num));//所有数标记为素数
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
  solve(1000);
  for (int i = 1; i <= 100; i++)
    cout << i << " " << num[i] << endl;
  return 0;
}