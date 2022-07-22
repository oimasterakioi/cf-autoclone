#include<bits/stdc++.h>
using namespace std;
#define int long long
void clear(){
}
void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+2];
	for(int i=1;i<=n;++i)
		cin>>a[i];
	a[0]=a[n+1]=0;
	int pre[n+2],back[n+2];
	pre[0]=0;
	int last=0;
	for(int i=1;i<=n;++i){
		if(a[i]<a[i-1])
			last+=a[i-1]-a[i];
		pre[i]=last;
	}
	back[n+1]=0;
	last=0;
	for(int i=n;i>=1;--i){
		if(a[i]<a[i+1])
			last+=a[i+1]-a[i];
		back[i]=last;
	}
	while(m--){
		int from,to;
		cin>>from>>to;
		if(from<to)
			cout<<pre[to]-pre[from];
		else
			cout<<back[to]-back[from];
		cout<<endl;
	}
}
main(){
	int t=1;
//	cin>>t;
	while(t--){
		clear();
		solve();
	}
	return 0;
}
