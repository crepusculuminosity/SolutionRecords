#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e7 + 10;
using ll = long long;
constexpr ll mod = 1e9 + 7;
int num[maxn], prime[maxn], cnt;

ll f[maxn];
void init() {
  for (int i = 2; i < maxn; i++) {
    if (!num[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
      num[i * prime[j]] = 1;
      if (i % prime[j]==0)
        break;
    }
  }
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  f[1]=1;
  /*for (int i = 2; i < maxn; i++) {
    if (!num[i])
      f[i] = f[i - 1] * (i - 1) % mod;
    else
      f[i] = f[i - 1] * i % mod;
  }*/
  for(int i=2;i<=maxn-90;i++)
	{
		(num[i])?f[i]=f[i-1]*i:f[i]=f[i-1]*(i-1);
		f[i]%=mod;
	}
  
  /*int n, m;
  while (cin >> n >> m && m + n) {
    ll ans = f[m];
    for (int i = m + 1; i <= n; i++)
      ans = ans * i % mod;
    cout << ans-1 << '\n';
  }*/
  for(int i=1;i<=1000;i++)
    cout<<f[i]<<endl;
  return 0;
}