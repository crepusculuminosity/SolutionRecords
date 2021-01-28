#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int prime[MAXN];
int main() {
  for (int i = 0; i < MAXN; i++)
    prime[i] = 1;
  prime[0] = prime[1] = 0;
  for (int i = 2; i < MAXN; i++) {
    if (!prime[i])
      continue;
    for (int j = i * 2; j < MAXN; j += i)
      prime[j] = 0;
  }
  int tmp, n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    if (prime[tmp])
      cout << tmp << " ";
  }
  return 0;
}