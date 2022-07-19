#include<bits/stdc++.h>
using namespace std;

#define int long long

void clear(){
}
void solve(){
	int n;
	cin >> n;
	int a[n + 1];
	for(int i = 1; i <= n; ++ i)
		cin >> a[i];
	
	if(n % 2 == 1){
		int tot = 0;
		for(int i = 2; i < n; i += 2){
			int maxtmp = 0;
			if(a[i] <= a[i - 1]){
				maxtmp = max(maxtmp, a[i - 1] + 1 - a[i]);
			}
			if(a[i] <= a[i + 1]){
				maxtmp = max(maxtmp, a[i + 1] + 1 - a[i]);
			}
			tot += maxtmp;
		}
		cout << tot << endl;
	}
	else{
		int tot = 0;
		int atot[n + 1];
		for(int i = 2; i < n; i += 2){
			int maxtmp = 0;
			if(a[i] <= a[i - 1]){
				maxtmp = max(maxtmp, a[i - 1] + 1 - a[i]);
			}
			if(a[i] <= a[i + 1]){
				maxtmp = max(maxtmp, a[i + 1] + 1 - a[i]);
			}
			tot += maxtmp;
			atot[i] = tot;
		}
		int tot2 = 0;
		int atot2[n + 1];
		for(int i = n - 1; i >= 2; i -= 2){
			int maxtmp = 0;
			if(a[i] <= a[i - 1]){
				maxtmp = max(maxtmp, a[i - 1] + 1 - a[i]);
			}
			if(a[i] <= a[i + 1]){
				maxtmp = max(maxtmp, a[i + 1] + 1 - a[i]);
			}
			tot2 += maxtmp;
			atot2[i] = tot2;
		}
		
// 		for(int i = 1; i <= n; ++ i)
// 			cout << atot[i] << ' ';
// 		cout << endl;
// 		for(int i = 1; i <= n; ++ i)
// 			cout << atot2[i] << ' ';
// 		cout << endl;
		
		int tot3 = 1000000000000000;
		for(int i = 2; i + 3 < n; i += 2){
			tot3 = min(tot3, atot[i] + atot2[i + 3]);
		}
		
		cout << min(min(tot, tot2), tot3) << endl;
	}
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
