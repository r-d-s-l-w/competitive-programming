#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int x, length; string txt; vector <int> a; vector <int> b;
    while (cin >> x >> txt)
    {
        length=0;
        for(int i=0; i<2*x; i++)
            txt[i]=='K'?a.push_back(i):b.push_back(i);
        for(int i=0; i<x; i++)
            length+=max(a[i],b[i])-min(a[i],b[i]);
        cout << length << "\n";
        a.clear(); b.clear();
    }
}
