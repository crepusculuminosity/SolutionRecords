#include <bits/stdc++.h>
using namespace std;
int num[20000], prime[20000];
int cnt;

void pre() {
  num[2] = 0;
  for (int i = 2; i < 19999; i++) {
    if (num[i] == 0) {
      for (int j = i * 2; j < 19999; j += i)
        num[j] = 1;
      prime[++cnt] = i;
    }
  }
}

int main() {
  // freopen("data.out","w",stdout);
  pre();
  cout << prime[2019];
  return 0;
}
