#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int maxi,n=1;

    for(int i=0 ; i<(s.size()-1) ; i++){
        if(s[i] == s[i+1])
        {
            n++;
            if(maxi<n)
                maxi=n;
        }
        else
        {
            n=1;
        }
    }

    cout << maxi;
}
