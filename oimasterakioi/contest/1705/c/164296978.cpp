#include<iostream>
using namespace std;

#define int long long

int n, c, q;
string s;

struct node{
	int st;
	int ed;
	int ost;
	int oed;
}a[50];

int curid;

int getid(int q){
	for(int i = 1; i <= c; ++ i)
		if(a[i].st <= q && a[i].ed >= q){
			int id = q - a[i].st;
			return a[i].ost + id;
		}
}

void solve(){
	cin >> n >> c >> q;
	cin >> s;
	
	s = " " + s;
	
	curid = s.size();
	
	for(int i = 1; i <= c; ++ i){
		int x;
		int y;
		cin >> x >> y;
		a[i].ost = x;
		a[i].oed = y;
		a[i].st = curid;
		a[i].ed = curid + (y - x + 1) - 1;
		curid += (y - x + 1);
	}
	
	
	while(q --){
		int x;
		cin >> x;
		while(x >= s.size())
			x = getid(x);
		
		cout << s[x] << endl;
	}
}
signed main(){
	int t;
	cin >> t;
	while(t--)
		solve();
}