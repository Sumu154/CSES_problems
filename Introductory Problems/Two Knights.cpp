#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int k;
    cin >> k;
    long long int total,attack,non_attack;

    for(long long int i=1 ; i<=k ; i++){
        total= ((i*i)*(i*i-1))/2;
        attack= (4*(i-1)*(i-2));
        non_attack = total - attack;

        cout << non_attack << "\n";

    }
}
