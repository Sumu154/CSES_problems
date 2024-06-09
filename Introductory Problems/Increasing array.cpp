#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,a,moves=0;
    cin >> n;
    vector<int> arr;

    for(int i=0 ; i<n ; i++){
         cin >> a;
         arr.push_back(a);
    }

    for(int i=0 ; i<n-1 ; i++){
        if(arr[i] > arr[i+1])
        {
            moves= moves+arr[i]-arr[i+1];
            arr[i+1]= arr[i];
        }
    }

    cout << moves;
}
