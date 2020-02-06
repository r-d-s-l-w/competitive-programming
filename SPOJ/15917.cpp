#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        char x;
        cin >> n;
        cin >> x;
        if (x=='?'&&n==1) cout << "10";
        else if (x=='?') cout << "9";
        else cout << "1";
        for (int i=1; i<n; i++)
        {
            cin >> x; if (x=='?') cout <<"0";
        }
        cout << "\n";
    }
    return 0;
}
