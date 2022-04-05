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
		int i;
		int j;
		for(j=1;j<=n;++j)
			if(a[j]>a[j+1])
				break;
		if(j>n){
			cout<<0<<endl;
			continue;
		}
		for(i=1;i<=n;++i){
			if(i%2==1)
				for(int i=1;i<=n;i+=2){
					if(a[i]>a[i+1])
						swap(a[i],a[i+1]);
				}
			else
				for(int i=2;i<=n;i+=2){
					if(a[i]>a[i+1])
						swap(a[i],a[i+1]);
				}
			for(j=1;j<=n;++j)
				if(a[j]>a[j+1])
					break;
			if(j>n)
				break;
		}
		cout<<i<<endl;
	}
}