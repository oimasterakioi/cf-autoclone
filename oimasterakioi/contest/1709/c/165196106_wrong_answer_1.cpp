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
	bool flag=true;
	while(flag){
		flag=false;
		int last=0;
		int noback=1;
		for(int i=n;i>=1;--i)
			if(s[i]=='?'){
				noback=i;
				break;
			}
		for(int i=1;i<=n;++i)
			if(s[i]=='?'){
				if(last==0){
					s[i]='(';
					++last;
					flag=true;
				}
				else if(n-last+1<=last&&i>=noback){
					s[i]=')';
					--last;
					flag=true;
				}
				else
					break;
			}
			else if(s[i]=='(')
				++last;
			else
				--last;
		last=0;
		int no=n;
		for(int i=1;i<=n;++i)
			if(s[i]=='?'){
				no=i;
				break;
			}
		for(int i=n;i>=1;--i)
			if(s[i]=='?'){
				if(last==0){
					s[i]=')';
					++last;
					flag=true;
				}
				else if(last>=i&&i<=no){
					s[i]='(';
					--last;
					flag=true;
				}
				else
					break;
			}
			else if(s[i]==')')
				++last;
			else
				--last;
	}
	flag=false;
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