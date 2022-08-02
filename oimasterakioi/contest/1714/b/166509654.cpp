#include<iostream>
#include<set>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;++i)
		cin>>a[i];
	set<int>se;
	int st=0;
	for(int i=n;i>=1;--i){
		int siz=se.size();
		se.insert(a[i]);
		if(se.size()==siz){
			st=i;
			break;
		}
	}
	cout<<st<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
