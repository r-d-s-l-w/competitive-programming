#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, x, q, y=1073741825, xd, s; vector <int> tab; vector <int> arr;
    cin >> n;
    while (n--) {cin >> x; arr.push_back(x); if (y==x) xd++;  else {y=x; xd=0;}  if (xd==2)tab.push_back(x);}
    cin >> q;
    while (q--)
        {
            cin >> x;
            if (binary_search(tab.begin(), tab.end(), x)) cout << "Tak\n";
            else if (binary_search(arr.begin(), arr.end(), x)) cout << "Nie\n";
            else cout << "brak\n";
        }
}
