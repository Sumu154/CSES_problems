#include<bits/stdc++.h>
using namespace std;
#define mod ((int)1e9+7)

int main()
{
    int n;
    cin >> n;
    int result= 1;

    for(int i=1 ; i<=n ; i++){
        result = 2*result;
        if(result > mod)
            result = result%mod;
    }

    cout << result;
}
