#include<iostream>
using namespace std;
void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int j=0;
	while(j<s.size()&&s[j]=='?')
		++j;
	if(j==s.size()){
		for(int i=0;i<n;++i)
			if(i%2==0)
				cout<<'R';
			else
				cout<<'B';
		cout<<endl;
	}
	else{
		for(int i=j+1;i<n;++i)
			if(s[i]=='?')
				if(s[i-1]=='R')
					s[i]='B';
				else
					s[i]='R';
		for(int i=j-1;i>=0;--i)
			if(s[i+1]=='R')
				s[i]='B';
			else
				s[i]='R';
		cout<<s<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
