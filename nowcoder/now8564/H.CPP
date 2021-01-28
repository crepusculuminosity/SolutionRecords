#include <bits/stdc++.h>
using namespace std;

int main(){
    double x1,y1,r1,x2,y2,r2;
    double dis,dir;
    int _; cin>>_;
    while(_--){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        dir=max(r1-r2,r2-r1);
        if(dir<=dis&&dis<=r1+r2)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}