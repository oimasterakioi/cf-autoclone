#include<iostream>
#include<algorithm>
using namespace std;
void solve(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int a[2 * n + 1];
    int b[n + 1];
    for(int i = 1; i <= 2 * n; ++ i)
        cin >> a[i];
    sort(a + 1, a + 2 * n + 1);
    bool flag = true;
    for(int i = 1; i <= n; ++ i)
        if(a[i + n] - a[i] < x)
            flag = false;
    
    if(flag == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
}