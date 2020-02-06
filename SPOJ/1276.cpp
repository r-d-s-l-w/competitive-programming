#include <iostream>
#include <string>
using namespace std;

int main()
{
    string txt;
    while(getline(cin,txt))
    {
        for(int i=txt.length()-1; i>=0;i--)
        {
            if(txt[i]==32&&txt[i+1]<='z'&&txt[i+1]>='a') txt[i+1]=char(txt[i+1]-32);
        }
        for(int i=0; i<txt.length(); i++) {if(txt[i]!=32&&txt[i]!=0)cout <<txt[i];}
        cout << endl;
    }
    return 0;
}
