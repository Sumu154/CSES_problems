/*
// https://www.youtube.com/watch?v=kzeAHV2Pw2o
retrieve any cycle of a directed graph

1---->3
^    /^
|   / |
|  /  |
| v   |
2---->4

4 5

1 3
2 1
2 4
3 2
3 4

Output
4
2 1 3 2

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int visited[N];
bool flag[N];
vector<int> adja_list[N];
stack<int> st;
int n, m;

bool DFS(int source)
{
    visited[source] = 1;
    st.push(source);
    flag[source] = true;
    for(int i : adja_list[source]){
        if(visited[i] == 0)
        {
            bool cycle = DFS(i);
            if(cycle)
                return true;
        }
        else if(flag[i] == 1)
        {
            st.push(i);
            return true;
        }
    }
    st.pop();
    flag[source] = false;
    return false;
}

void print_cycle()
{
    vector<int> ans;
    int temp = st.top();
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
        if (ans.back() == temp && ans.size() != 1)
            break;
    }

    cout << ans.size() << "\n";
    reverse(ans.begin(), ans.end());
    for (int i : ans)
    {
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
        print_cycle();
    else
        cout << "IMPOSSIBLE";
}






