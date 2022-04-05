#include<iostream>
using namespace std;
#define int long long
int n;
int d[200010];
int p;
int lowbit(int x){
	return x&(-x);
}
void add2(int i,int k){
	if(i>n)
		return;
//	d[i]=(d[i]+k+p)%p;
	d[i]+=k;
	add2(i+lowbit(i),k);
}
void add(int i,int j,int k){
	add2(i,k);
	add2(j+1,-k);
}
int query(int i){
	if(i<=0)
		return 0;
	return d[i]+query(i-lowbit(i));
}
signed main(){
	cin>>n;
	cin>>p;
	add(n,n,1);
	for(int i=n;i>=2;--i){
		int qq=query(i);
		add(1,i-1,qq);
		for(int j=i;j>=2;--j){
			int tmp=i/j;
			add(tmp,tmp,qq);
		}
	}
	cout<<query(1)%p<<endl;
}