#include <bits/stdc++.h>

using namespace std;

string tab[100000];

int str_to_int (string a){
    int x = 0;
    int temp = 1;
    for (int i = a.length() - 1; i >= 0; --i){
        x += temp * (a[i] - 48);
        temp *= 10;
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string number;
    while (cin >> number){
        int i = 0;
        sort(number.begin(), number.end());
        do {
            //cout << number << endl;
            tab[i] = number;
            ++i;
        } while (next_permutation(number.begin(), number.end()));
        for (int j = i - 1; j >= 0; --j)
            cout << str_to_int(tab[j]) << endl;
    }
}
