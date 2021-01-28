#include <bits/stdc++.h>
using namespace std;

struct GoldHeaps{
    int w;
    int v;
}a[105];

bool cmp(GoldHeaps& a, GoldHeaps& b){//a更有价值
    return a.v*b.w>a.w*b.v;
}

int main()
{
    int n,m;cin>>n>>m;
    double ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i].w>>a[i].v;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(a[i].w<=m) ans+=a[i].v,m-=a[i].w;
        else{
            ans+=a[i].v*m*1.0/(a[i].w);
            break;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}

