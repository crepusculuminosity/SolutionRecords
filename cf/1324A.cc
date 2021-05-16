#include <bits/stdc++.h>
using namespace std;
int a[110];
int main() {
 // freopen("data.in","r",stdin);
  int _;
  cin >> _;
  while (_--) {
    bool f=1;
    int n, k;
    cin>>n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (i == 1)
        k = x % 2;
      else if (x% 2 != k)
        f=0;
      
    }
    if(f) puts("YES");
    else puts("NO");
  }
  return 0;
}