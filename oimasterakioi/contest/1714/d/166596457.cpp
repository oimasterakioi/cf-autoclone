#include<iostream>
#include<vector>
using namespace std;
bool check(string t,string s,int i){
	if(i<1)
		return false;
	if(i+(s.size()-1)-1>t.size()-1)
		return false;
	for(int k=1;k<s.size();++k)
		if(s[k]!=t[i+k-1])
			return false;
	return true;
}
void solve(){
	string t;
	cin>>t;
	int n=t.size();
	t=" "+t;
	int m;
	cin>>m;
	int f[n+1];
	for(int i=0;i<=n;++i)
		f[i]=0;
	string s[m+1];
	for(int i=1;i<=m;++i)
		cin>>s[i];
	for(int i=1;i<=m;++i)
		s[i]=" "+s[i];
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)
			if(check(t,s[i],j)){
				f[j]=max(f[j],(int)(j+s[i].size()-1-1));
			}
	}
	for(int i=1;i<=n;++i)
		f[i]=max(f[i],f[i-1]);
	int tot=0;
	vector<pair<int,int>>ans;
	for(int i=1;i<=n;++i){
		if(f[i]<i){
			// cannot arrive
			cout<<-1<<endl;
			return;
		}
		++tot;
		for(int j=1;j<=m;++j)
			if(check(t,s[j],f[i]-s[j].size()+1+1)&&f[i]-s[j].size()+1+1<=i){
				ans.emplace_back(j,f[i]-s[j].size()+1+1);
				break;
			}
		i=f[i];
	}
	cout<<tot<<endl;
	for(auto i:ans)
		cout<<i.first<<' '<<i.second<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
