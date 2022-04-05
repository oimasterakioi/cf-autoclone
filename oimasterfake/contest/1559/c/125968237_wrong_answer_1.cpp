#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;++i)
			cin>>a[i];
		if(a[n]==0){
			for(int i=1;i<=n+1;++i)
				cout<<i<<' ';
			cout<<endl;
		}
		else{
			int j=-1;
			for(int i=1;i<n;++i)
				if(a[i]==0&&a[i+1]==1){
					j=i;
					break;
				}
			if(j==-1){
				cout<<-1<<endl;
			}
			else{
				for(int i=1;i<=j;++i)
					cout<<i<<' ';
				cout<<n+1<<' ';
				for(int i=j;i<=n;++i)
					cout<<i<<endl;
			}
		}
	}
} 
