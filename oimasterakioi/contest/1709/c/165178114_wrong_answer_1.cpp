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
	int last=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='?'){
			if(last==0){
				s[i]='(';
				++last;
			}
			else if(n-last+1<=last){
				s[i]=')';
				--last;
			}
			else
				break;
		}
		else if(s[i]=='(')
			++last;
		else
			--last;
	last=0;
	for(int i=n;i>=1;--i)
		if(s[i]=='?'){
			if(last==0){
				s[i]=')';
				++last;
			}
			else if(last>=i){
				s[i]='(';
				--last;
			}
			else
				break;
		}
		else if(s[i]==')')
			++last;
		else
			--last;
	bool flag=false;
	for(int i=1;i<=n;++i)
		if(s[i]=='?')
			flag=true;
	if(flag)
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
