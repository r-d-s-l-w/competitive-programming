#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt;
    char x;
    while(cin >> txt)
    {
        cin.get(x);
        cout << txt[0];
        if(txt.find(".")!=string::npos&&x!='\n') cout << " ";
        if(x=='\n') cout << endl;
    }
}
