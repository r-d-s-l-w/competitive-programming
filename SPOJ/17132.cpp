#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, n, a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector <bool> tab(1000001, false);
        vector <int> arr(n, 0);
        for (int i=0; i<n; i++)
        {
            cin >> a;
            if (tab[a]==false) {tab[a]=true; arr[i]=a;}
        }
        int xd=1, p=0;
        for (int i=0; i<n; i++)
        {
            if (arr[i]==0) while (true){if (tab[xd]==false){arr[i]=xd; xd++; break;} else xd++;}
            else p++;
        }
        if (p==n) cout << "OK\n";
        else {for (int i=0; i<n; i++) cout << arr[i] << " "; cout << endl;}
    }
}
