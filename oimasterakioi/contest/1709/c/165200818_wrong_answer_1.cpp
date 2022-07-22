#include<bits/stdc++.h>
using namespace std;
#define int long long
void clear(){
}
int n;
void solve(){
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	s[1]='(';
	s[n]=')';
	int tot=0;
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='(')
			++tot;
		else if(s[i]==')')
			--tot;
		else
			++cnt;
	if(abs(tot)!=cnt)
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