#include <iostream>
using namespace std;

int main()
{
    string x; int l;
    while (getline(cin, x))
    {
        l=x.length();
        char txt[l];
        for (int i=0; i<l; i++)
        {
            if (i%2==0&&i+1!=l) txt[i]=x[i+1];
            else if (i%2==1) txt[i]=x[i-1];
            else txt[i]=x[i];
            cout << txt[i];
        }
        cout << endl;
    }
    return 0;
}
