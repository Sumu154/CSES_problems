/*
    2-----3
     \   /
      \ /
       1
       |
       |
       4----5

5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int visited[N];  //jei node visited hoye jabe oita 1 banaye dibo
vector<int> adja_list[N]; //grpagh ta rakhar jonno
vector<int> parent(N, -1);

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] =1;
    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int i:adja_list[head]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                parent[i] = head;
            }
        }
    }
}

int main()
{
    int n, m , u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    int src = 1;
    BFS(src);

    if(!visited[n]){
        cout << "IMPOSSIBLE";
    }
    else{
        vector<int> ans;
        while(n!=-1){
            ans.push_back(n);
            n = parent[n];
        }
        cout << ans.size() << "\n";
        reverse(ans.begin(), ans.end());

        for(int i: ans){
            cout << i << " ";
        }
    }

}

