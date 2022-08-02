#include<iostream>
using namespace std;
void res(int n,int st){
	if(n<=st){
		cout<<n;
		return;
	}
	res(n-st,st-1);
	cout<<st;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		res(n,9);
		cout<<endl;
	}
}
