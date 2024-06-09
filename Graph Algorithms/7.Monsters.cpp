#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1005;
char maze[N][N];
int g[N][N];
vector<pair<int, int>> monster;
map<pair<int,int>, pair<int, int>> mp;   //parent mapping er jonno
pair<int, int> src, dst;
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dir[] = {'R', 'L', 'D', 'U'};


bool isValid(int x, int y, int time){
    if(x<0 or y<0 or x>=n or y>=m){
        return false;
    }
    if(g[x][y] <= time){
        return false;
    }
    return true;
}

bool isEscape(int x, int y, int time){
    if(!isValid(x, y, time)){
        return false;
    }
    if((x==0 or y==0 or x==n-1 or y==m-1) and maze[x][y] != 'M'){
        return true;
    }
    return false;
}

bool BFS()
{
    queue<pair<pair<int,int>, int>> q;
    q.push({src, 0});
    mp[src] = {-1, -1};

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int time = q.front().second;

        q.pop();
        time++;

        for(int i=0 ; i<4 ; i++){
            int tx = x+dx[i];
            int ty = y+dy[i];

            if(isEscape(tx, ty, time)){
                mp[{tx, ty}] = {x, y};
                dst = {tx, ty};
                return true;
            }
            if(isValid(tx, ty, time)){
                mp[{tx, ty}] = {x, y};
                g[tx][ty] = time;
                q.push({{tx, ty}, time});
            }
        }
    }
    return false;
}

void lava_flow()
{
    queue<pair<pair<int, int>, int>> q;
    for(auto i: monster){
        q.push({i, 0});
    }

    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int time = q.front().second;

        q.pop();
        time++;

        for(int i=0; i<4; i++){
            int tx = cx+dx[i];
            int ty = cy+dy[i];

            if(isValid(tx, ty, time)){
                g[tx][ty] = time;
                q.push({{tx, ty}, time});
            }
        }
    }
}

void path_print()
{
    pair<int, int> tmp = dst;
    pair<int, int> tmp1 = mp[dst];
    pair<int, int> end = {-1, -1};

    string path = "";

    while(tmp1 != end){
        int diff_x = tmp.first - tmp1.first;
        int diff_y = tmp.second - tmp1.second;
        for (int i=0 ; i<4 ; i++){
            if(dx[i]==diff_x and dy[i]==diff_y){
                path+= (dir[i]);
                break;
            }
        }
        tmp = tmp1;
        tmp1 = mp[tmp];
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    cout << path << "\n";
}


int main()
{
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> maze[i][j];

            if(maze[i][j] == 'M'){
                g[i][j] = 0;
                monster.push_back({i, j});
            }
            else if(maze[i][j] == 'A'){
                g[i][j] = 0;
                src = {i, j};
            }
            else if(maze[i][j] == '#'){
                g[i][j] = 0;
            }
            else{
                g[i][j] = INT_MAX;
            }
        }
    }

    if(src.first==0  or  src.second==0  or src.first==n-1 or src.second==m-1){
        cout << "YES\n" << 0 << "\n";
        return 0;
    }

    lava_flow();

    if(!BFS()){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        path_print();

    }

}