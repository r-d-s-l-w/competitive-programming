#include <iostream>
using namespace std;

int main()
{
    long int t,n;
    cin>>t;
    while(t--)
    {
        long int ile_zer=0;
        cin >> n;
        ile_zer=n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625+n/1953125+n/9765625+n/48828125+n/244140625;
        cout << ile_zer << endl;
    }
    return 0;
}
