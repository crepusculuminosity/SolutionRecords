#include <bits/stdc++.h>
using namespace std;
int r;
int a[1005][1005],dp[1005][1005];
int main()
{
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            dp[i][j]=a[i][j];
        }
    }
    for(int i=r-1;i>=1;i--)
        for(int j=1;j<=i;j++)
            dp[i][j]=max(dp[i+1][j], dp[i+1][j+1])+a[i][j];
        
    cout<<dp[1][1]<<endl;
    return 0;
}