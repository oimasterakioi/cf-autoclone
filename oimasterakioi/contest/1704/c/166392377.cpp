#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	int a[m+1];
	for(int i=1;i<=m;++i)
		cin>>a[i];
	sort(a+1,a+m+1);
	int b[m+1];
	for(int i=1;i<m;++i)
		b[i]=a[i+1]-a[i]-1;
	b[m]=a[1]+n-a[m]-1;
	sort(b+1,b+m+1);
	
	int safe=0;
	int gan=2*m;
	for(int i=1;i<=m;++i){
		gan-=2;
		if(b[i]-2*gan==1){
			// | x | -> only 1
			++safe;
		}
		else if(b[i]-2*gan-1>0){
			// | wall x x x wall |
			safe+=b[i]-2*gan-1;
		}
	}
	cout<<n-safe<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
