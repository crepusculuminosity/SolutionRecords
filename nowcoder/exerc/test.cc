#include <bits/stdc++.h>
using namespace std;
int a[1000] = {0, 1, 3, 5, 6, 11, 15, 45, 55, 60, 76};
int m = 10;

int find(int x) {
  int l = 1, r = m;
  int res;
  while (l < r) {
    int mid = (r + l + 1) >> 1;
    if (a[mid] <= x)
      l = mid;
    else
      r = mid - 1;
  }
  if (a[l] == x)
    l--;
  return l;
}

int main() {
  for (int i = 1; i <= m; i++)
    cout << a[i] << " ";
  cout << endl;
  while (1) {
    int n;
    cin >> n;
    cout << find(n) << " " << a[find(n)] << endl;
  }
  return 0;
}