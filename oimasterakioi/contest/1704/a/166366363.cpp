#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	s=" "+s;
	t=" "+t;
	
	int last=n-m;
	for(int i=2;i<=m;++i)
		if(s[i+last]!=t[i]){
			cout<<"NO"<<endl;
			return;
		}
	for(int i=1;i<=last+1;++i)
		if(s[i]==t[1]){
			cout<<"YES"<<endl;
			return;
		}
	cout<<"NO"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
