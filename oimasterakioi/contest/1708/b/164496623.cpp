#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	
	vector<int> output;
	
	for(int i = n; i >= 1; -- i){
		int least = (l + i - 1) / i * i;
//		while(least <= r){
//			least += i;
//		}
		if(least > r){
			cout << "NO" << endl;
			return;
		}
//		ans.insert(least);
		output.push_back(least);
	}
	
	reverse(output.begin(), output.end());
	
	cout << "YES" << endl;
	for(auto i : output)
		cout << i << ' ';
	cout << endl;
}

main(){
	int t = 1;
	cin >> t;
	while(t --)
		solve();
}
