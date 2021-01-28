#include <bits/stdc++.h>
using namespace std;
const int MAXN=2*1e8+5;
int vis[MAXN];

void getPrime()
{
    memset(vis, 1, sizeof vis);
    vis[0]=vis[1]=0;
    for(int i=2;i<MAXN;i++){
        if(!vis[i]) continue;
        for(int j=i*2;j<MAXN;j++)
            vis[j]=0;
    }
}

int main()
{
    getPrime();
    int n,i; cin>>n;
    for(i=2;i<n/i;i++){
        if(vis[i]) break;
    }
    cout<<max(i,n/i)<<endl;
}