#include <iostream>

using namespace std;

unsigned long long pow (unsigned long long x, unsigned long long k){
    unsigned long long int wynik = 1;
    for (int i=0; i<k; ++i)
        wynik *= x;
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long t, n, x, tab[7], wynik;
    cin >> t;
    while (t--){

            wynik = 0;

        for (int i = 1; i < 8; ++i)
            tab[i] = 0;

        cin >> n;
        for (int i = 0; i < n; ++i){
            cin >> x;
            tab[x]++;
        }
        if (tab[5] == 0 && tab[6] == 0){
            if (tab[1] != 0 || tab[2] != 0 || tab[3] != 0)
                cout << -1 << endl;
            else cout << 1 << endl;
        }
        else {
            for (int i = 1; i < 40; ++i){
                unsigned long long x = 1 * tab[1] + pow(2, i) * tab[2] + pow(3, i) * tab[3] + pow(4, i) * tab[4]
                + pow(5, i) * tab[5] + pow(6, i) * tab[6];
                unsigned long long y = pow(4, i) * n;
            if (x >= y){
                cout << i << endl;
                break;
                }
            }
        }
    }
}
