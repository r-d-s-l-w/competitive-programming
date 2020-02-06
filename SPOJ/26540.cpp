#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string txt;
    cin >> txt;
    for (int i = 0; i < txt.length(); i += 7){
        int x = 0;
        for (int j = 1; j < 7; j += 2){
            x += 16 * (txt[i + j] - 48);
            if (txt[i + j + 1] >= 'A') x += txt[i + j + 1] - 55;
            else x += txt[i + j + 1] - 48;
        }
        cout << char(x);
    }
}
