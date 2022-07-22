#include<bits/stdc++.h>
using namespace std;
#define int long long
void clear(){
}
void solve(){
	int x;
	cin>>x;
	int a[5];
	cin>>a[1]>>a[2]>>a[3];
	if(a[x]==0||a[a[x]]==0)
		cout<<"NO";
	else
		cout<<"YES";
	cout<<endl;
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
