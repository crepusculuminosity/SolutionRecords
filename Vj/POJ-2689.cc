#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int num[maxn], prime[maxn], prime2[maxn];
int cnt;

/*void init() {
  for (int i = 2; i <= (1 << 16); i++) {
    if (num[i] == 0) {
      prime[++cnt] = i;
      for (int j = 1; j <= cnt && prime[j] * i <= (1 << 16); j++) {
        num[i * prime[j]] = 1;
        if (i % prime[j] == 0)
          break;
      }
    }
  }
}*/

void init() {
  for (int i = 2; i <= (1 << 16); i++) {
    if (num[i] == 0) {
      prime[++cnt] = i;
      for (int j = i * 2; j <= (1 << 16); j += i)
        num[j] = 1;
    }
  }
}

void solve(int L, int R) {
  int i, j, p;
  memset(num, 0, sizeof(num));
  for (int i = 1; i <= cnt; i++) {
    p = L / prime[i];
    while (p <= 1)
      p++;
    for (j = prime[i] * p; j <= R; j += prime[i]) {
      if (j >= L)
        num[j - L] = 1;
    }
  }
  if (L == 1)
    num[0] = 1;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  init();
  int L, R;
  while (~scanf("%d%d", &L, &R)) {
    // memset(num, 0, sizeof(num));
    // int tot=0;
    // for(int i=0;i<=R-L;i++)
    int tot = 0;
    solve(L, R);
    int minn = 0x3f3f3f3f, maxn = -0x3f3f3f3f;
    int maxl, minl, maxr, minr;
    for (int i = 0; i <= R - L; i++) {
      if (!num[i])
        prime2[++tot] = i + L;
    }
    // cout<<tot<<endl;//for(int i=1;i<=tot;i++) cout<<prime2[i]<<' ';
    // cout << endl;
    if (tot <= 1) // cout<<"There are no adjacent primes.\n";
      printf("There are no adjacent primes.\n");
    else {
      for (int i = 1; i < tot; i++) {
        if (prime2[i + 1] - prime2[i] > maxn) {
          maxn = prime2[i + 1] - prime2[i];
          maxl = prime2[i], maxr = prime2[i + 1];
        }
        if (prime2[i + 1] - prime2[i] < minn) {
          minn = prime2[i + 1] - prime2[i];
          minl = prime2[i], minr = prime2[i + 1];
        }
      }
      // cout << minl << ',' << minr << " are closest, " << maxl << ',' << maxr
      //     << " are most distant.\n";
      printf("%d,%d are closest, %d,%d are most distant.\n", minl, minr, maxl,
             maxr);
    }
  }
  return 0;
}