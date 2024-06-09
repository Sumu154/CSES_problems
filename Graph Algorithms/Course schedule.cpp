/*
1---->2
^
|     4---->5
|
3

5 3
1 2
3 1
4 5

Output 3 4 1 5 2
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int visited[N];
vector<int> adja_list[N];
stack<int> st;

bool DFS(int source)
{
    visited[source] = 1;
    for(int i:adja_list[source]){
        if(visited[i] == 0)
        {
            bool cycle = DFS(i);
            if(cycle)
                return true;
        }
        else if(visited[i] == 1)
        {
            return true;
        }
    }
    st.push(source);  //kono node done holei stacke push korbo
    visited[source] = 2;
    return false;
}

int main()
{
    //n = num of nodes
    //m = num of edges
    int n, m, u, v;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++){
        cin >> u >> v;
        adja_list[u].push_back(v);
    }

    bool found = false;
    for(int i=1 ; i<=n ; i++){
        if(visited[i] == 0)
        {
            bool cycle = DFS(i);
            if(cycle)
            {
                found = true;
                break;
            }
        }
    }

    if(found)
        cout << "IMPOSSIBLE";
    else
    {
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }

    }
}
