#include<bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(int a, int b){
	if(a == 0)
		return false;
	if(b == 0)
		return true;
	return a < b;
}

void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	bool zero = false;
	while(true){
//		for(int i = 1; i <= n; ++ i)
//			cout << a[i] << ' ';
//		cout << zero << endl;
		if(zero)
			a[n + 1] = a[1];
		for(int i = 1; i < n; ++ i){
			a[i] = a[i + 1] - a[i];
			if(a[i] == 0)
				zero = true;
		}
		if(zero){
			a[n] = a[n + 1];
			a[n + 1] = 0;
		}
		else
			a[n] = 0;
		sort(a + 1, a + n + 1, cmp);
		while(n > 1 && a[n] == 0)
			-- n;
		if(n == 1)
			break;
	}
	cout << a[1] << endl;
}

main(){
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}
