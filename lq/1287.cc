#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int n;

  while (cin >> n) {
    int f=1;

    for(int a=0; a*a<=n/4&&f; ++a)
      for(int b=a; a*a+b*b<=n/2&&f; ++b)
        for(int c=b; 4*(a*a+b*b+c*c)<=3*n&&f; ++c) {
          int t=n-a*a-b*b-c*c;
          int d=floor(sqrt(t)+0.5);

          if(d*d==t&&d>=c) {
            f=0;
            cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
          }
        }
  }

  return 0;
}
