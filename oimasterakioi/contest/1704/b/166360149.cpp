#include<iostream>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int minv=a[1];
	int maxv=a[1];
	int tot=0;
	for(int i=2;i<=n;++i){
		minv=min(minv,a[i]);
		maxv=max(maxv,a[i]);
		if(maxv-minv>2*m){
			maxv=a[i];
			minv=a[i];
			++tot;
		}
	}
	cout<<tot<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
