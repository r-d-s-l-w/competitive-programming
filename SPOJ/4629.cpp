#include <iostream>
using namespace std;

int main()
{
    string txt; int n, wynik;
    cin >> n;
    while (n--)
    {
        cin>>txt;
        wynik=txt[0]-48;
        for (int i=1; i<txt.length(); i=i+2)
        {
            if(txt[i]=='+')wynik+=txt[i+1]-48;
            else wynik-=txt[i+1]-48;
        }
        cout << wynik << endl;
    }
    return 0;
}
