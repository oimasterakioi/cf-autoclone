#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int a[100010];
int lasteven[100010];
int lastodd[100010];
int ans[100010];
int sumeven[100010];
int sumodd[100010];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	for(int i = 1; i <= n; ++ i)
		lasteven[i] = lastodd[i] = ans[i] = sumeven[i] = sumodd[i] = 0;
	
	for(int i = 1; i <= n; ++ i){
		int now = a[i];
		if(i % 2 == 0){
			if(lasteven[now] == 0){
				lasteven[now] = i;
				sumeven[now] = 1;
				ans[now] = max(ans[now], 1LL);
			}
			if(lastodd[now] != 0){
				sumeven[now] = sumodd[now] + 1;
				ans[now] = max(ans[now], sumeven[now]);
			}
		}
		else{
			if(lastodd[now] == 0){
				lastodd[now] = i;
				sumodd[now] = 1;
				ans[now] = max(ans[now], 1LL);
			}
			if(lasteven[now] != 0){
				sumodd[now] = sumeven[now] + 1;
				ans[now] = max(ans[now], sumodd[now]);
			}
		}
	}
	
	for(int i = 1; i <= n; ++ i)
		cout << ans[i] << ' ';
	
	cout << endl;
}

main(){
	ios::sync_with_stdio(false);
	int t = 1;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}
