#include<bits/stdc++.h>
using namespace std;

const int N = 1002;
char maze[N][N];
int visited[N][N];
int level[N][N];
pair<int,int> parent[N][N];
int n, m;
pair<int,int> src, dst;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'U', 'D'};

bool isValid(int x, int y)
{
    if(x>=0 and x<n and y>=0 and y<m and maze[x][y]!='#' and !visited[x][y]){
        return true;
    }
    return false;
}

void BFS(pair<int,int> src)
{
    queue<pair<int,int>> q;
    q.push(src);
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    while(!q.empty()){
        pair<int,int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i=0 ; i<4 ; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(isValid(newX, newY)){
                visited[newX][newY] = 1;
                q.push({newX, newY});

                level[newX][newY] = level[x][y]+1;
                parent[newX][newY] = {x, y};
            }
        }
    }
}

string path_print()
{
    string path = "";
    int x = dst.first;
    int y = dst.second;

    while(x!= src.first or y != src.second){
        int px = parent[x][y].first;
        int py = parent[x][y].second;

        for(int i=0 ; i<4 ; i++){
            if(px+dx[i]==x and py+dy[i]==y){
                path += dir[i];
                break;
            }
        }
        x = px;
        y = py;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'A'){
                src = {i,j};
            }
            else if(maze[i][j] == 'B'){
                dst = {i,j};
            }
        }
    }

    BFS(src);
    if(!visited[dst.first][dst.second]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n" << level[dst.first][dst.second] << "\n";
        cout << path_print() << "\n";
    }
}
