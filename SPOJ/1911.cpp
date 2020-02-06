#include <iostream>
#include <string>
using namespace std;

int main()
{
    string txt;
    while (getline(cin, txt))
    {
        int x=0,y=0;
        for(int i=0; i<txt.length(); i++)
        {
            if(txt[i]==' '){if (txt[i-1]>='0'&&txt[i-1]<='9') x++; else y++;}
        }
        if (txt[txt.length()-1]<='9'&&txt[txt.length()-1]>='0') x++; else y++;
        cout << x << " " << y << endl;
    }
    return 0;
}
