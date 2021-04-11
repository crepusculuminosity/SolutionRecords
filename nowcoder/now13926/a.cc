#include <bits/stdc++.h>
using namespace std;
int s[50];
int main() {
  int n;
  // scanf("%d", &n);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  // vector<int> s(n);
  // for (int &x:s) scanf("%d", &x);
  sort(s, s + n);
  double p = 1, r = 0;
  while (n--)
    r += (p *= 0.5) * s[n];
  printf("%.5lf\n", r);
}
