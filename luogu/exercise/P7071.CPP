#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[25];
int main(){
    ll n,cnt=0;
    cin>>n;
    if(n&1) cout<<-1<<endl;
    else {
        while (n)
        {
            a[cnt++]=n%2;
            n>>=1;
        }
        for(int i=24; i>=0; i--) 
             if(a[i]>0) cout<<(ll)pow(2,i)<<" ";
        cout<<endl;
        
    }
    return 0;
}