#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
int prime[MAXN];

void getPrime() {
  memset(prime, 1, sizeof prime);
  prime[0] = prime[1] = 0;
  for (int i = 2; i < MAXN; i++) {
    if (!prime[i])
      continue;
    for (int j = i * 2; j < MAXN; j += i)
      prime[j] = 0;
  }
}

bool isPdNum(int n) {
  int num = n, y = 0;
  while (n) {
    y *= 10;
    y += n % 10;
    n /= 10;
  }
  return num == y;
}

int main() {
  getPrime();
  int a, b;

  cin >> a >> b;
  if (b >= 9989899)
    b = 9989899;
  for (int i = a; i <= b; i++) {
    if (isPdNum(i) && prime[i])
      cout << i << endl;
  }
  return 0;
}