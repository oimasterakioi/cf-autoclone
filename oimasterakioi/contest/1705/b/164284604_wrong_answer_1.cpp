#include<iostream>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	int last = 1;
	while(last <= n && a[last] == 0)
		++ last;
	if(last == n){
		cout << 0 << endl;
		return;
	}
	
	int tot = 0;
	
	for(int i = last; i < n; ++ i){
		if(a[i] != 0)
			continue;
		while(last <= n && a[last] == 0)
			++ last;
		++ a[i];
		-- a[last];
		++ tot;
	}
	
	for(int i = last; i < n; ++ i)
		tot += a[i];
	
	cout << tot << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
}