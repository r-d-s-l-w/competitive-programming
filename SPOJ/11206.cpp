#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    while (k--)
    {
        string txt;
        cin >> txt;
        int x=min(txt[0]-65, 91-txt[0]);
        for (int i=1; i<txt.length(); i++)
        x+=min((26+txt[i]-txt[i-1])%26, (26+txt[i-1]-txt[i])%26);
        cout << x << "\n";
    }
    return 0;
}
