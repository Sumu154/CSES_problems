/*

4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2

Output
YES
1 2 4 1

*/

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

const int N = 1e5+5;
vector<int> d(N, INF);
int parent[N];
vector<pair<int, int>> adja_list[N];
int n, m;

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adja_list[u].push_back({v,w});
    }

    bool found = false;
    int updated = -1;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            for(pair<int,int> k:adja_list[j])
            {
                int u = j;
                int v = k.first;
                int w = k.second;

                if(d[u]+w < d[v])
                {
                    d[v] = d[u]+w;
                    parent[v] = u;
                    if(i==n)
                    {
                        found = true;
                        updated = v;
                    }
                }
            }
        }
    }

    if(found)
    {
        cout << "YES\n";
        int selected = updated;
        for(int i=1 ; i<=n ; i++){
            selected = parent[selected];
        }

        int first = selected;
        vector<int> cycle;
        cycle.push_back(selected);
        while(true)
        {
            selected = parent[selected];
            cycle.push_back(selected);
            if(selected == first)
                break;

        }

        reverse(cycle.begin(), cycle.end());
        for(int i:cycle){
            cout << i << " ";
        }
        cout << "\n";
    }
    else
        cout << "NO";

}
