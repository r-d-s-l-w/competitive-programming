#include <iostream>
#include <string>
using namespace std;
int main()
{
    string txt;
    while(getline(cin,txt))
    {
        for(int i=0; i<txt.length(); i++)
        {
    if (txt[i]>=65 && txt[i]<=90) cout<<char((txt[i]-65+13)%26+65);
    else if (txt[i]>=97 && txt[i]<=122) cout<<char((txt[i]-97+13)%26+97);
    else if (txt[i]>=48 && txt[i]<=57) cout<<char((txt[i]-48+5)%10+48);
    else cout<<txt[i];
        }
        cout<<endl;
    }
    return 0;
}
