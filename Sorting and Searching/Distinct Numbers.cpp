#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,a,counts=1;
    cin >> n;
    vector<int> arr;

    for(int i=0 ; i<n ; i++){
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(),arr.end());

    for(int i=0 ; i<n-1 ; i++){
        if(arr[i] != arr[i+1])
        {
            counts++;
        }
    }

    cout << counts;



}
