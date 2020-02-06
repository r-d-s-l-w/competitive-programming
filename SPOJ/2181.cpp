#include <iostream>
using namespace std;

int main()
{
    char x; string y;
    while(cin>>x>>y)
    {
        for(int i=0; i<y.length(); i++)
        {
            if (y[i]!=x) cout << y[i];
        }
        cout << endl;
    }
    return 0;
}
