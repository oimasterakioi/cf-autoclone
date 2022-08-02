#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;++i)
		cin>>a[i];
	bool flag=true;
	for(int i=2;i<=n;++i){
		if(a[i]!=a[i-1]){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<"YES"<<endl;
		return;
	}
	flag=false;
	for(int i=1;i<=n;++i)
		if(a[i]%5==0){
			flag=true;
			break;
		}
	if(flag==true){
		for(int i=1;i<=n;++i)
			if(a[i]%10==5)
				a[i]+=5;
		for(int i=2;i<=n;++i)
			if(a[i]!=a[i-1]){
				flag=false;
				break;
			}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		return;
	}
	for(int i=1;i<=n;++i)
		if(a[i]%10%2==1)
			a[i]+=a[i]%10;
	bool t[n+1];
	for(int i=1;i<=n;++i){
		while(a[i]%10!=2)
			a[i]+=a[i]%10;
		if(a[i]/10%2==0)
			t[i]=false;
		else
			t[i]=true;
	}
	flag=true;
	for(int i=2;i<=n;++i)
		if(t[i]!=t[i-1]){
			flag=false;
			break;
		}
	if(flag){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
