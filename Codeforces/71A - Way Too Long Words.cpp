#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int k;
    cin >> k;
    while (k--)
    {
        cin >> txt;
        txt.length()>10?cout<<txt[0]<<txt.length()-2<<txt[txt.length()-1]<<"\n":cout<<txt<<"\n";
    }
}
