#include<bits/stdc++.h>
using namespace std;
#define int long long
void clear(){
}
int n;
struct bit{
	int d[200010];
	bit(){
		for(int i=0;i<=n+10;++i)
			d[i]=0;
	}
	int lowbit(int x){
		return x&(-x);
	}
	int query(int x){
		if(x==0)
			return 0;
		return d[x]+query(x-lowbit(x));
	}
	void update(int i,int x){
		if(i>n)
			return;
		d[i]+=x;
		update(i+lowbit(i),x);
	}
};
int gb(int i){
	return n-i+1;
}
void solve(){
	string s;
	cin>>s;
	n=s.size();
	s=" "+s;
//	int pre[n+5];
//	pre[0]=0;
	s[1]='(';
	s[n]=')';
	bit pre;
	bit preun;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')
			pre.update(i,1);
		else if(s[i]==')')
			pre.update(i,-1);
		else
			preun.update(i,1);
	}
//	int back[n+5];
//	back[n+1]=0;
	bit back;
	bit backun;
	for(int i=n;i>=1;--i){
		if(s[i]=='(')
			back.update(gb(i),-1);
		else if(s[i]==')')
			back.update(gb(i),1);
		else
			backun.update(gb(i),1);
	}
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=2;i<n;++i){
			if(preun.query(i-1)!=0&&backun.query(gb(i+1))!=0)
				continue;
			if(pre.query(i-1)==back.query(gb(i+1))-1){
				s[i]='(';
				pre.update(i,1);
				back.update(gb(i),-1);
				flag=true;
			}
			else if(pre.query(i-1)==back.query(gb(i+1))+1){
				s[i]=')';
				pre.update(i,-1);
				back.update(gb(i),1);
				flag=false;
			}
		}
	}
//	flag=false;
	for(int i=1;i<=n;++i)
		if(s[i]=='?'){
			flag=true;
			break;
		}
	if(flag==false)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
main(){
	int t=1;
	cin>>t;
	while(t--){
		clear();
		solve();
	}
	return 0;
}
