#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    long long int r,c;

    for(int i=0 ; i<t ; i++){
        cin >> r >> c;

        if(r >= c)
        {
            if(r%2 == 0)  //row even
                cout << (r*r)-(c-1) << "\n";
            else         //row odd
                cout << (r-1)*(r-1)+c << "\n";

        }

        else  //r<c
        {
            if(c%2 ==0)  //col even
                cout <<  (c-1)*(c-1)+r << "\n";
            else
                cout << (c*c)-(r-1) << "\n";
        }
    }
}
