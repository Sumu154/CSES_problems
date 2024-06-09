/*

4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3

*/

#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

const int N = 1e4;
long long d[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++)
        {
            d[i][j] = INF;
        }
    }

    for(int i=0 ; i<m ; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;

        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for(int i=1 ; i<=n ; i++){
        d[i][i] = 0;
    }

    for(int k=1 ; k<=n ; k++){  //k = intermidiate node
        for(int u=1 ; u<=n ; u++){
            for(int v=1 ; v<=n ; v++)
            {
                d[u][v] = min(d[u][v], d[u][k]+d[k][v]);
            }
        }
    }

    for(int i=0 ; i<q ; i++){
        int u, v;
        cin >> u >> v;
        if(d[u][v] == INF)
            cout << "-1\n";
        else
            cout << d[u][v] << "\n";
    }
}

