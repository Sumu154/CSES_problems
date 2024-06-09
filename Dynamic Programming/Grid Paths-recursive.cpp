/*
https://atcoder.jp/contests/dp/tasks/dp_h

1.define state
      fun(n) -> number of unique path from 0,0 to n-1,n-1

2.recursive eqn from smaller sub problem
      fun(n, m) = fun(n-1, n) + fun(n, n-1)

3.define base case
      fun(1, 1) = 1;

4
....
.*..
...*
*...
output
3

*/

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

const int N = 1002;
char grid[N][N];
int dp[N][N];

int GridPath(int n, int m)
{
     //1.handle base case
     if(grid[n][m] != '.')
        return 0;
     if(n==1 and m==1)
        return 1;

    //2.if current state is already solved,return the solved result
    if(dp[n][m] != -1)
        return dp[n][m];

    //3.calculate the result from smaller sub problem
    int ans = 0;
    if(n>1 and grid[n][m]=='.')
        ans += GridPath(n-1, m)%mod;

    if(m>1 and grid[n][m]=='.')
        ans += GridPath(n, m-1)%mod;

    dp[n][m] = ans%mod;
    return ans%mod;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << GridPath(n, n);
}
