#include <bits/stdc++.h>
using namespace std;
const int maxn=32*100010;
int trie[maxn][2],tot=1,num[maxn];
void insert(int n) {
	int p=1;
	for(int i=31;i>=0;i--) {
		int ch=(n>>i)&1;
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
}

int query(int n) {
	int p=1, ans=0;
	for(int i=31;i>=0;i--) {
		int ch=(n>>i)&1,o=ch^1;
		if(trie[p][o]) p=trie[p][o],ans=ans<<1|1;
		else p=trie[p][ch],ans<<=1;
	}
	return ans;
}


int main() {
	//freopen("data.in","r",stdin);
	int n; cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) {
		int num; cin>>num;
		ans=max(ans,query(num));
		insert(num); 
	}
	cout<<ans;
	return 0;
}