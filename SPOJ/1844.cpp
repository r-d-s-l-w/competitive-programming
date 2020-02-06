#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    while(cin>>a>>n){
        int licz=0;
        while(n--)
        {
            cin>>b;
            if(b==a)licz++;
        }
        cout << licz << endl;
    }
    return 0;
}
