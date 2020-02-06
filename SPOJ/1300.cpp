#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string txt;
    while (getline(cin, txt)){
    for(int i=0; i<txt.length(); i++)
    {if(txt[i]>='A'&&txt[i]<='Z') cout << char(((txt[i]+3)-65)%26+65); else cout << txt[i];} cout << endl;}
    return 0;
}
