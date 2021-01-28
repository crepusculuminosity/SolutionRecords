#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e8 + 5;

int prime[MAXN];
int main() {
  for (int i = 0; i < MAXN; i++) //假设全部都为素数
    prime[i] = 1;
  prime[0] = prime[1] = 0; //
  for (int i = 2; i < MAXN; i++) {
    if (!prime[i])
      continue;
    for (int j = i * 2; j < MAXN; j += i) //素数的倍数都是合数
      prime[j] = 0;
  }
  for (int i = 0; i < 1000; i++)
    cout << i << " " << prime[i] << endl;
  return 0;
}

//