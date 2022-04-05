#include<iostream>
using namespace std;
int main(){
	#define int long long
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;++i)
			cin>>a[i];
		for(int i=2;i<=n;++i)
			a[i]&=a[i-1];
		cout<<a[n]<<endl;
	}
}