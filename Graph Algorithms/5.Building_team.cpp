/*
5 3
1 2
1 3
4 5

Output may be
1 2 2 1 2
1 2 2 2 1
2 1 1 2 1
2 1 1 2 1

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int visited[N];
int color[N];
vector<int> adja_list[N];
long long int n = 1e7, m = 1e7;

bool DFS(int source)
{
    visited[source] = 1;
    for(int i:adja_list[source]){
        if(visited[i] == 0)
        {
            //assign a ditterent color to adja node
            if(color[source] == 1)
                color[i] = 2;
            else
               color[i] = 1;

            bool is_bicolorabe = DFS(i);
            if(!is_bicolorabe)
                return false;
        }
        else
        {
            //check if the colore is same or different
            if(color[source] == color[i])
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        long long int u, v;
        cin >> u >> v;

        adja_list[u].push_back(v);
        adja_list[v].push_back(u);
    }

    bool is_bicolorabe = true;
    for(int i=1 ; i<=n ; i++){
        if(visited[i] == 0)
        {
            color[i] = 1;
            bool ok = DFS(i);
            if(!ok)
            {
                is_bicolorabe = false;
                break;
            }
        }
    }

    if(!is_bicolorabe)
        cout << "IMPOSSIBLE";
    else
    {
        for(int i=1 ; i<=n ; i++){
            cout << color[i] << " ";
        }
    }
}
