#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    vector <string> txt;
    vector <string> tab;
    vector <string> arr;
    string x; char y;
    do
    {
        cin >> x;
        y=cin.get();
        txt.push_back(x);
    } while (y!='\n');
    do
    {
        cin >> x;
        y=cin.get();
        tab.push_back(x);
    } while (y!='\n');
    int xd=0;
    for (int i=0; i<txt.size(); i++)
    {
        if (txt[i]==tab[xd]) xd++;
        else arr.push_back(txt[i]);
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << "\n";
}
