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

void clear(){
	n = 0;
	memset(a, 0, sizeof(a));
	memset(lasteven, 0, sizeof(lasteven));
	memset(lastodd, 0, sizeof(lastodd));
	memset(ans, 0, sizeof(ans));
	memset(sumeven, 0, sizeof(sumeven));
	memset(sumodd, 0, sizeof(sumodd));
}
void solve(){
	cin >> n;
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
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
	int t = 1;
	cin >> t;
	while(t --){
		clear();
		solve();
	}
	return 0;
}
