/*
https://www.youtube.com/watch?v=qYyyj2SRsRc
retrieve any cycle of a undirected graph

1-------2
|\      |
| \     |
|  \    |
3---5---4

5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output
4
3 5 1 3

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int> adja_list[N];
int visited[N];
int parent[N];
int n, m;
int start, last;

bool DFS(int src, int p)
{
    visited[src] = 1;
    parent[src] = p;

    for(int i: adja_list[src]){
        if(i==p){
            continue;
        }
        else if(!visited[i]){
            if(DFS(i,src)){
                return true;
            }
        }
        else if(visited[i]){
           start = i;
           last = src;
           return true;
        }
    }
    return false;
}

void print_cycle()
{
    vector<int> path;
    int a = last;
    path.push_back(last);
    while(a != start){
        path.push_back(parent[a]);
        a = parent[a];
    }
    path.push_back(last);

    cout << path.size() << "\n";
    reverse(path.begin(), path.end());
    for(int i: path){
        cout << i << " ";
    }
}


int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v;
        cin >> u >> v;

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    bool found = false;
    for(int i=1 ; i<=n ; i++){
        if(!visited[i]){
            if(DFS(i, -1)){
                found = true;
                break;
            }
        }
    }

    if(found)
        print_cycle();
    else
        cout << "IMPOSSIBLE";
}


