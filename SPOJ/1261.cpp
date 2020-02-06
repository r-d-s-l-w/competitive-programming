#include <iostream>
using namespace std;

int main()
{
    string pesel;
    int k;
    cin >> k;
    while(k--)
    {
        cin >> pesel;
        if(((pesel[0]-48)*1+(pesel[1]-48)*3+(pesel[2]-48)*7+(pesel[3]-48)*9+(pesel[4]-48)*1+(pesel[5]-48)*3+(pesel[6]-48)*7+(pesel[7]-48)*9+(pesel[8]-48)*1+(pesel[9]-48)*3+(pesel[10]-48)*1)%10==0) cout << "D" << endl;
        else cout << "N" << endl;
    }
    return 0;
}
