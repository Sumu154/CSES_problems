/*

dot deagula purata ekta ghor..ber korte hbe kotogula emn ghor ace

5 8
########
#..#...#
####.#.#
#..#...#
########

output -> 3

while there is empty cell
- find an empty unvisited cell
- run bfs or dfs from that cell

                                             _x_______y_
(x,y) er 1.right cell -> (x, y+1)             0       1
         2.left cell  -> (x, y-1)             0      -1
         3.up cell    -> (x+1, y)             1       0
         4.down cell  -> (x-1, y)            -1       0

direction array
         dx[] = {0, 0, -1, 1}
         dy[] = {1, -1, 0, 0}


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2000;
int visited[N][N];
int maze[N][N];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(x>=0 && x<n && y>=0 && y<m)
        return true;

    return false;
}

bool is_forbidden(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if(maze[x][y] == -1)
        return true;

    return false;
}

void DFS(pair<int, int> source)
{
    int x = source.first;
    int y = source.second;

    visited[x][y] = 1;
    for(int i=0 ; i<4 ; i++){
        int new_x = x+dx[i];
        int new_y = y+dy[i];

        pair<int, int> adja_node = {new_x, new_y};
        if(visited[new_x][new_y]==0 && is_inside(adja_node) && !is_forbidden(adja_node))
        {
                DFS({new_x, new_y});
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        string input;
        cin >> input;
        for(int j=0 ; j<m ; j++)
        {
            if(input[j] == '#')
                maze[i][j] = -1;
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == 0 && visited[i][j] == 0) {
                DFS({i, j});
                count++;
            }
        }
    }
    cout << count;
}

