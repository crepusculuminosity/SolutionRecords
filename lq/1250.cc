#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;

  while(~scanf("%d",&n)) {
    int f=1;

    for(int a=1; 3*a*a<=n; ++a)
      for(int b=a; 3*(a*a+b*b)<=2*n; ++b) {
        int c=n-a*a-b*b;
        int d=floor(sqrt(c)+0.5);

        if(d*d==c) {
          f=0;
          printf("%d %d %d\n",a,b,d);
        }
      }

    if(f) printf("No Solution\n");
  }

  return 0;
}
