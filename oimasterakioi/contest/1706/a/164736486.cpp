#include<bits/stdc++.h>
using namespace std;

#define int long long

void clear(){
}
void solve(){
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	string s = " ";
	for(int i = 1; i <= m; ++ i)
		s += 'B';
	for(int i = 1; i <= n; ++ i){
		int now = min(m + 1 - a[i], a[i]);
		if(s[now] == 'A')
			now = m + 1 - now;
		s[now] = 'A';
	}
	
	cout << s.substr(1) << endl;
}

main(){
	int t = 1;
	cin >> t;
	while(t --){
		clear();
		solve();
	}
	return 0;
}
