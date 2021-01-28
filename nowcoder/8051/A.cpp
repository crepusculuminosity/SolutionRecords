#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e12 + 5;
int num[MAXN], prime[MAXN];
ll cnt;

void solve(ll n) {
  // memset(num,1,sizeof(num));//所有数标记为素数
  num[1] = 0;
  for (ll i = 2; i <= n; i++) {
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
  solve(MAXN);
  for (ll i = 1; i <= MAXN; i++) {
    if (!prime[i])
      cout << i << " " << prime[i] << endl;
  }
  return 0;
}