#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define int long long

void solve(){
	int n;
	cin >> n;
	string s;
	string t;
	cin >> s >> t;
	
	s = " " + s;
	t = " " + t;
	
	if(s[1] != t[1] || s[n] != t[n]){
		cout << -1 << endl;
		return;
	}
	
	vector<int> ids;
	vector<int> idt;
	
	for(int i = 1; i < n; ++ i)
		if(s[i] != s[i + 1])
			ids.push_back(i);
			
	for(int i = 1; i < n; ++ i)
		if(t[i] != t[i + 1])
			idt.push_back(i);
	
	if(ids.size() != idt.size()){
		cout << -1 << endl;
		return;
	}
	
	int cnt = 0;
	for(int i = 0; i < ids.size(); ++ i){
		cnt += abs(ids[i] - idt[i]);
	}
	
	cout << cnt << endl;
}

main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}