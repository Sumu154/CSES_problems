#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    if(n==2 || n==3)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        for(int i=1 ; i<=n ; i++){
            if(i%2 == 0)
            {
                cout << i << " ";
            }
        }
        for(int i=1 ; i<=n ; i++){
            if(i%2 != 0)
            {
                cout << i << " ";
            }
        }

    }
}
