#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int d, tab[26]; string txt; unsigned long long int x, mini; vector <int> xd;
    cin >> d;
    while (d--)
    {
        for (int i=0; i<26; i++) tab[i]=0;
        cin >> txt; x=1;
        for (int i=0; i<txt.length(); i++)
            tab[txt[i]-97]++;
        for (int i=0; i<26; i++) if (tab[i]>1) xd.push_back(tab[i]);
        int s=xd.size()-1;
        for (int i=txt.length(); i>0; i--)
        {
            x*=i;
            if (s>=0){
            while (x%xd[s]==0&&xd[s]!=1) {x/=xd[s]; xd[s]--;}
            if (xd[s]==1) s--;}
        }
        cout << x << endl;
        xd.erase(xd.begin(),xd.end());
    }
}
