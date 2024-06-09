#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,a;
    cin >> n;
    int arr[n+1];

    for(int i=1 ; i<n ; i++){
        cin >> a;
        arr[a]= 1;
    }

    for(int i=1 ; i<=n ; i++){
        if(arr[i] != 1)
            cout << i;
    }
}
