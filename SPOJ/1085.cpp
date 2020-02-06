#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll tab[100100];
ll odl[100100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, x; ll wynik = 0;
    cin >> n;
    for (int i=0; i<n; ++i){
        cin >> tab[i] >> x;
        x>0?wynik+=x:wynik-=x;
    }
    sort(tab, tab+n);
    //for (int i=0; i<n; ++i) cout << tab[i] << ' ';
    for (int i=1; i<n; ++i){
        odl[i] = tab[i] - tab[i-1];
        wynik += tab[i] - tab[0];
    }
    for (int i=1; i<n; ++i){
        if (odl[i]*i - odl[i]*(n-i)<0 || odl[i] == 0) wynik += odl[i]*i - odl[i]*(n-i);
        else {
            cout << tab[i-1] << ' ' << wynik;
            break;
        }
    }
    if (n==1) cout << tab[0] << ' ' << wynik;

}
