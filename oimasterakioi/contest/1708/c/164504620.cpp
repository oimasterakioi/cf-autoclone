#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n, q;
	cin >> n >> q;
	int a[n + 1];
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	if(q > n){
		for(int i = 1; i <= n; ++ i)
			cout << 1;
		cout << endl;
		return;
	}
	
	int currq = 0;
	bool ans[n + 1];
	
	for(int i = n; i >= 1; -- i){
		if(a[i] <= currq)
			ans[i] = 1;
		else{
			if(currq == q)
				ans[i] = 0;
			else{
				++ currq;
				ans[i] = 1;
			}
		}
	}
	
	for(int i = 1; i <= n; ++ i)
		cout << ans[i];
	cout << endl;
}

main(){
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}
