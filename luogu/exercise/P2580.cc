#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int trie[maxn][26],tot=1,cnt[maxn];
char s[100];
void insert(char *str) {
	int len=strlen(str),p=1;
	for(int i=0;i<len;i++) {
		int ch=str[i]-'a';
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	cnt[p]=1;
}
int search(char *str) {
	int len=strlen(str),p=1,res=0;
	for(int i=0;i<len;i++) {
		p=trie[p][str[i]-'a'];
		if(p==0) return 0;
	}
	return cnt[p]++;
}


int main() {
	
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		insert(s);
	}
	cin>>m;
	for(int i=1;i<=m;i++) {
		cin>>s;
		int num=search(s);
		if(!num) cout<<"WRONG\n";
		else if(num==1) cout<<"OK\n";
		else cout<<"REPEAT\n";
	}
	return 0;
}
