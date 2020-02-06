#include <iostream>
using namespace std;

int main()
{
    int t; string a,b;
    cin>>t;
    while (t--)
    {
        int j=0;
        cin>>a>>b;
        for (int i=0; i<a.length(); i++)
            if (a[i]==b[j]) j++;
        if (j==b.length()) cout << "Tak" << endl;
        else cout << "Nie" << endl;
    }
    return 0;
}
