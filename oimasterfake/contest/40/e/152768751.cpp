#include <iostream>
#include <ostream>
#define int long long

int qsm(int a, int b, int mod){
    if(b == 1){
        return a % mod;
    }
    if(b == 0)
        return 1;
    
    int temp = qsm(a, b/2, mod);
    temp = temp * temp % mod;
    if(b & 1)
        temp = temp * a % mod;
    
    return temp;
}

signed main(){

    int n, m, p, k;
    std::cin >> n >> m;

    std::cin >> k;

    bool swapped = false;
    if(n>m){
        swapped = true;
        std::swap(n, m);
    }

    int cnt[m+1];
    int num[m+1];

    for(int i = 1; i <= m; ++ i)
        num[i] = 1;
    for(int i = 1; i <= m; ++ i)
        cnt[i] = 0;
    
    while(k--){
        int x,y,z;
        std::cin >> x >> y >> z;
        if(swapped)
            std::swap(x, y);
        
        num[y] *= z;
        ++cnt[y];
    }

    std::cin >> p;

    if((n+m) %2 != 0){
        std::cout << 0 << std::endl;
        return 0;
    }

    bool needspace = true;
    int ans = 1;

    for(int i=1; i <= m; ++ i){
        if(cnt[i] == 0 && needspace == true){
            needspace = false;
            continue;
        }

        if(cnt[i] == n){
            // full
            // verify
            if(num[i] == -1)
                continue;
            
            std::cout << 0 << std::endl;
            return 0;
        }

        ans = ans * qsm(2, n - 1 - cnt[i], p) % p;
        // std::cout << i << ' ' << cnt[i] << ' ' << num[i] << std::endl;
    }

    std::cout << ans << std::endl;

    return 0;
}