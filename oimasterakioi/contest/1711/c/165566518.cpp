#include<bits/stdc++.h>
using namespace std;
#define int long long
void clear(){
}
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[k+1];
	for(int i=1;i<=k;++i)
		cin>>a[i];
	sort(a+1,a+k+1);
	int cnt=0;
	bool three=false;
	if(n%2==0)
		three=true;
	for(int i=1;i<=k;++i)
		if(a[i]/m>=2){
			cnt+=a[i]/m;
			if(a[i]/m>=3)
				three=true;
		}
	if(cnt>=n&&three){
		cout<<"YES"<<endl;
		return;
	}
	if(m%2==0)
		three=true;
	else
		three=false;
	cnt=0;
	for(int i=1;i<=k;++i)
		if(a[i]/n>=2){
			cnt+=a[i]/n;
			if(a[i]/n>=3)
				three=true;
		}
	if(cnt>=m&&three){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
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
