#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll a[maxn],t[maxn];
#define lb(x) (x&-x)
int n,m;

void init() {
	for(int i=1;i<=n;i++) {
		t[i]+=a[i];
		int j=i+lb(i);
		if(j<=n) t[j]+=t[i];
	}
}
void update(int x, int v) {
	while(x<=n) {
		t[x]+=v;
		x+=lb(x);
	}
}
ll getsum(int x) {
	int res=0;
	while(x) {
		res+=t[x];
		x-=lb(x);
	}
	return res;
}

int query(int l ,int r ,int k) {
	if(l==r) return l;
	int mid=r+l>>1;
	ll nl=getsum(mid)-getsum(l-1);
	if(k<=nl) return query(l,mid,k);
	else return query(mid+1,r,k-nl);
}


int main() {
	freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	init();
	for(int i=1;i<=n;i++) cout<<t[i]<<' ';
	cout<<'\n';
	while(m--) {
		int a,b,c,u;
		cin>>a>>b>>c>>u;
		if(a==0) {
			for(int i=b;i<=c;i++) update(i,u);
		} else cout<<query(b,c,u)<<'\n';
	}
	return 0;
}














