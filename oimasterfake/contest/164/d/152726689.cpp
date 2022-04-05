#include <iostream>
#include <vector>
using namespace std;

#define int long long

int n, k;
int x[1010], y[1010];
// int dis[1010][1010];

int getdis(int x1, int y1, int x2, int y2){
    int x = x1 - x2;
    int y = y1 - y2;
    return x * x + y * y;
}

struct edge{
    int next;
    int to;
}e[3000000];

int head[1010];
int cnt;

void add_edge(int u, int v){
    ++ cnt;
    e[cnt].next = head[u];
    head[u] = cnt;
    e[cnt].to = v;
}

bool d[1010];
bool ans[1010];

int deg[1010];

void remove(int u){
    d[u] = false;

    for(int i = head[u]; i; i = e[i].next){
        if(d[e[i].to] == true){
            -- deg[u];
            -- deg[e[i].to];
        }
    }
}

void create(int u){
    d[u] = true;

    for(int i = head[u]; i; i = e[i].next){
        if(d[e[i].to] == true){
            ++ deg[u];
            ++ deg[e[i].to];
        }
    }
}

bool dfs(int k){
    // delete leaves' parents
    int leaf = 0;
    for(int i = 1; i <= n; ++ i)
        if(d[i] == true && deg[i] == 1){
            leaf = i;
            break;
        }
    
    if(leaf != 0){
        if(!k)
            return false;

        // found a leaf
        // get parent

        int parent = 0;
        for(int i = head[leaf]; i; i = e[i].next)
            if(d[e[i].to] == true){
                parent = e[i].to;
                break;
            }

        remove(parent);
        // dfs

        if(dfs(k-1)){
            // create(parent);
            return true;
        }
        create(parent);
        return false;
    }

    // delete max degree

    int maxv = 0;
    int maxi = -1;

    for(int i = 1; i <= n; ++ i){
        if(d[i] && deg[i] > maxv){
            maxv = deg[i];
            maxi = i;
        }
    }

    if(maxv == 0)
        return true; // delete successfully

    if(k == 0 /* && maxv != 0 */)
        return false; // delete was unsuccessful
    
    remove(maxi);
    if(dfs(k-1)){
        // create(maxi);
        return true;
    }

    create(maxi);
    // greedy another center *guess again xD*

    if(k - maxv >= 0 && maxv > 1){
        vector<int>centers;

        for(int i = head[maxi]; i; i = e[i].next){
            if(d[e[i].to])
                centers.push_back(e[i].to);
        }

        for(auto i : centers)
            remove(i);
        if(dfs(k - maxv)){
        //    for(auto i : centers)
        //        create(i);
            return true;
        }
        for(auto i : centers)
            create(i);
    }
    return false;
}

bool check(int mid){
    // clear graph
    cnt = 0;
    for(int i = 1; i <= n; ++i)
        deg[i] = 0;
        
    for(int i = 1; i <= n; ++i)
        head[i] = 0;
    
    for(int i = 1; i <= n; ++i)
        d[i] = true;
    
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++ j)
            if(getdis(x[i], y[i], x[j], y[j]) > mid){ // sqrare mid
                add_edge(i,j);
                ++deg[i];
            }
    
    // cout<<mid<<endl;
    // for(int i = 1; i <= n; ++ i)
    //     cout << deg[i] << ' ';
    // cout<<endl;

    if(dfs(k))
        return true;
    return false;
}

main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++ i)
        cin >> x[i] >> y[i];
    
    // for(int i = 1; i <= n; ++ i)
    //     for (int j = 1; j <= n; ++ j)
    //         dis[i][j] = getdis(x[i], y[i], x[j], y[j]); *MLE*

    // cout<<"hello"<<endl;
    
    int l = 0;
    int r = 2100000000;

    int mid;

    while (l + 1 < r){
        mid = (l + r) >> 1;
        
        if (check(mid)){
            for(int i = 1; i <= n; ++ i)
                ans[i] = !d[i];
            r = mid;
        }
        else
            l = mid;
    }

    int tot = 0;

    for(int i = 1; i <= n; ++i)
        if(ans[i] == true)
            ++tot;
    int i = 1;
    while(tot < k){
        if(ans[i] == false){
            ans[i] = true;
            ++tot;
        }
        ++i;
    }

    for(int i = 1; i <= n; ++i)
        if(ans[i] == true)
            cout<< i << ' ';

    return 0;
}