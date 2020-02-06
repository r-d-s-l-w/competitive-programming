#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define ll long long

ll n, m, x;
ll a[10100], b[10100];
bool exi[1000003];
bool exi2[1000033];
bool exi3[215312636];

bool poss(){
    for (int i=0; i<n; ++i){
        ll diff = x - a[i];
        if (diff >= 0 && exi[diff%1000003] && exi2[diff%1000033] && exi3[diff%215312636])
            return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i){
        cin >> b[i];
        exi[b[i]%1000003] = true;
        exi2[b[i]%1000033] = true;
        exi3[b[i]%215312636] = true;
    }

    while(m--){
        cin >> x;
        if (poss()) cout << "TAK\n";
        else cout << "NIE\n";
    }
}
