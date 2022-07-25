#include<bits/stdc++.h>
using namespace std;
#define int long long
void clear(){
}
struct node{
	int v;
	int id;
};
bool cmp(node a,node b){
	return a.v<b.v;
}
void solve(){
	int n,m;
	cin>>n>>m;
	node a[n+1];
	int b[n+1];
	for(int i=1;i<=n;++i){
		a[i].id=i;
		cin>>a[i].v;
		b[i]=a[i].v;
	}
	int f[n+1];
	for(int i=1;i<=n;++i)
		f[i]=0;
	int x[m+1];
	int y[m+1];
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i];
		++f[x[i]];
		++f[y[i]];
	}
	if(m%2==0||n==1){
		cout<<0<<endl;
		return;
	}
	sort(a+1,a+n+1,cmp);
	int minv=0x3f3f3f3f;
	for(int i=1;i<=n;++i)
		if(f[a[i].id]%2==1){
			minv=a[i].v;
			break;
		}
	for(int i=1;i<=m;++i)
		if(f[x[i]]%2==0&&f[y[i]]%2==0){
			minv=min(minv,b[x[i]]+b[y[i]]);
		}
	cout<<minv<<endl;
}
main(){
	int t=1;
	cin>>t;
	while(t--){
		clear();
		solve();
	}
	return 0;
}
