#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

const int N = 1e6+5;
vector<pair<int,ll>> adja_list[N];
int visited[N];
vector<ll> d(N, INF);
int n, m;

void Dijkstra(int src)
{
    d[src] = 0;
    priority_queue<pair<ll,int>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        pair<int,int> head = pq.top();
        pq.pop();
        int u = head.second;

        if(visited[u]){
            continue;
        }
        visited[u] = 1;
        for(auto i: adja_list[u]){
            int v = i.first;
            int w = i.second;

            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                pq.push({-d[v], v});
            } 
        }
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        ll u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
    }

    Dijkstra(1);
    for(int i=1 ; i<=n ; i++){
        cout << d[i] << " ";
    }
}