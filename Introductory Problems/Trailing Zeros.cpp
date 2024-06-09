#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int var=5,res=0;
    while(n >= var){
        res += n/var;
        var = var*5;
    }

    cout << res;
}
