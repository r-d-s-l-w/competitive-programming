#include <iostream>
#include <string>
using namespace std;
int main()
{
    string word, k, txt;
    cin >> word >> k >> txt;
    while(true){if (k[0]=='0') k.erase(0,1); else break;}
    if (word=="SZYFRUJ") for (int i=0; i<txt.length(); i++) cout << char((txt[i]-65+(k[i%k.length()]-48))%26+65);
    else for (int i=0; i<txt.length(); i++) cout << char((txt[i]-39-(k[i%k.length()]-48))%26+65);
    return 0;
}
