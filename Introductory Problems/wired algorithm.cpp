#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int n;
    cin >> n;

    cout << n << " ";
    while(n>1)
    {
        if(n%2 == 0 && n != 0)
        {
           n= n/2;
           cout << n << " ";
        }
         else if(n%2 != 0 && n != 0)
         {
            n= 3*n+1;
            cout << n << " ";
         }
    }
}
