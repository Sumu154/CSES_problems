#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;

    if(n%4 == 1 || n%4 == 2)
        cout << "NO";

    else if(n%4 == 0)
    {
        cout << "YES\n";
        cout << n/2 << "\n";
        for(int i=1 ; i<=n ; i+=4){
            cout << i << " " << i+3 << " ";
        }
        cout << "\n" << n/2 << "\n";
        for(int i=1 ; i<=n ; i+=4){
            cout << i+1 << " " << i+2 << " ";
        }
    }

    else   //(n%4 == 3)
    {
        cout << "YES\n";
        cout << n/2+1 << "\n";
        cout << "1" << " " << "2" << " ";
        for(int i=4 ; i<=n ; i+=4){
            cout << i << " " << i+3 << "\n";

        }
        cout << n/2 << "\n";
        cout << "3" << " ";
        for(int i=4 ; i<=n ; i+=4){
            cout << i+1 << " " << i+2 << "\n";

        }
    }
}
