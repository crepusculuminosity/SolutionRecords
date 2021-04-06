#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e8;
int main() {
  freopen("data.in","w",stdout);
  srand((unsigned)time(NULL));
  for(int i=1;i<=20;i++)
    cout<<(rand()%maxn)+1<<endl;
  for(int i=1;i<=100;i++)
    cout<<(rand()%maxn)+1+maxn<<endl;
  return 0;
}