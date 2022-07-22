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
	stack<int>st;
	for(int i=1;i<=n;++i)
		if(s[i]=='?')
			continue;
		else if(s[i]=='(')
			st.push(i);
		else{
			if(st.empty())
				continue;
			s[i]='_';
			s[st.top()]='_';
			st.pop();
		}
	string t=" ";
	for(int i=1;i<=n;++i)
		if(s[i]!='_')
			t+=s[i];
	int m=t.size()-1;
	// full
	int tot=0;
	int cnt=0;
	for(int i=1;i<=m;++i){
		if(s[i]=='(')
			++tot;
		else if(s[i]==')')
			--tot;
		else
			++cnt;
	}
//	cout<<t<<endl;
	if(abs(tot)==cnt){
		cout<<"YES"<<endl;
		return;
	}
	if(cnt==2){
		cout<<"YES"<<endl;
		return;
	}
	if(cnt==0){
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