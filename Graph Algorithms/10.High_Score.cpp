#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = -1e18;

const int N = 2505;
vector<ll> d(N, INF);
vector<pair<int,ll>> adja_list[N];
int n, m;

bool BellmanFord(int src)
{
    d[src] = 0;
    for(int i=1 ; i<=n ; i++){
        for(int u=1 ; u<=n ; u++){
            for(auto k: adja_list[u]){
                int v = k.first;
                ll w = k.second;
                if(d[u]+w > d[v]){
                    d[v] = d[u]+w;
                    if(i==n){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        ll  u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
        //adja_list[v].push_back({u,w});
    }

    int src = 1;
    if(BellmanFord(src)){
        cout << -1 << "\n";
    }
    else{
        cout << d[n] << "\n";
    }
}