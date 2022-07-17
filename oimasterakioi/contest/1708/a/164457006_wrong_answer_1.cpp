#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	int tot = 0;
	for(int i = 2; i <= n; ++ i)
		tot += a[i];
	
	if(tot % a[1] == 0)
		cout << "YES";
	else
		cout << "NO";
	cout<<endl;
}

main(){
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}
