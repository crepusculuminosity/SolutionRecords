#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Poi {
    ll x,y;
}p[100005];
Poi niu,zhi;
ll dis(Poi a, Poi b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}
double mind=3.0e8;
int main() {

    ll n; scanf("%lld",&n);
    for(ll i=1; i<=n; i++) {
        scanf("%lld",&p[i].x);
    }
    ll t; scanf("%lld",&t);
    ll md;
    while (t--)
    {
        scanf("%lld%lld%lld%lld",&niu.x,&niu.y,&zhi.x,&zhi.y);
        int cnt;
        if(niu.y*zhi.y>0) printf("%lld\n",dis(niu,zhi));
        else {
            double in=niu.x*1.0/(zhi.y-niu.y)*zhi.y-niu.y*1.0/(zhi.y-niu.y)*zhi.x;
            for(ll i=1; i<=n; i++) {
                if(abs(p[i].x-in)<=mind) {
                    mind=abs(p[i].x-in); cnt=i;
                }
            }
            printf("%lld\n",dis(niu,p[cnt])+dis(zhi,p[cnt]));
        }
        
    }
    
    
    return 0;
}