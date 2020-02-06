#include <iostream>
using namespace std;

int main()
{
    int n; string s;
    cin >> n >> s;
    for (int i=n/2; i>=0; i--)
    {
        for (int j=0; j<i; j++) cout << '.';
        for (int j=i; j<n-i; j++) cout << s[j];
        for (int j=0; j<i; j++) cout << '.';
        cout << endl;
    }

    return 0;
}
