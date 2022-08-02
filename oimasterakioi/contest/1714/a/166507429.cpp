#include<iostream>
#include<map>
using namespace std;
#define int long long
void solve(){
	int n,x;
	int a,b;
	cin>>n>>a>>b;
	x=a*60+b;
	int t[n+1];
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		t[i]=a*60+b;
	}
	int minv=1145141919810;
	for(int i=1;i<=n;++i)
		minv=min(minv,(t[i]+24*60-x)%(24*60));
	cout<<minv/60<<' '<<minv%60<<endl;
}
signed main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
