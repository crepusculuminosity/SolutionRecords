#include <bits/stdc++.h>
using namespace std;
const int M=110;
int a[M][M];
int b[M][M];

int main() {
  int n,m;
  //freopen("data.in","r",stdin);
  cin>>n>>m;

  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      cin>>a[i][j];

  for(int i=1; i<=m; i++){
    for(int j=1; j<=n; j++) {
      cout<<a[n-j+1][i]<<' ';
    }
    cout<<endl;
  }
}
