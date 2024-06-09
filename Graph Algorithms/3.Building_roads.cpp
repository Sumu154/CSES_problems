#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e7;
vector<long long> adja_list[N];
long long visited[N];
int n, m;
 
void DFS(int src)
{
    visited[src] = 1;
    for(int i: adja_list[src]){
        if(!visited[i]){
            DFS(i);
        }
    }
}
 
int main()
{
    int u, v;
    cin >> n >> m; 
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
 
        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }
 
    int src = 1;
 
    int count = 0;
    vector<int> ans;
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            count++;
            ans.push_back(i);
            DFS(i);
        }
    }
    cout << count-1 << "\n";
    for(int i=0 ; i<ans.size()-1 ; i++){
        cout << ans[i] << " " << ans[i+1] << "\n";
    }
    
}
