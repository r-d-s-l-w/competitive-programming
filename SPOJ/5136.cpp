#include <iostream>
using namespace std;

int main()
{
    string nr;
    while(cin>>nr)
    {
        if (nr=="0") break;
        int x=nr.length(), xd=0;
        for (int i=0; i<x; i++) xd+=nr[i]-48;
        if((nr[x-1]=='5'||nr[x-1]=='0')&&xd%3==0) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
    return 0;
}
