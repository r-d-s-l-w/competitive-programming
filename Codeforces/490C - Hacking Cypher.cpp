#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB emplace_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;

string x;
int a, b, tab[1000100], len;
vi resa, resb;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> x; len = x.length();
    cin >> a >> b;
    tab[0] = 1;
    for (int i=1; i<len; ++i)
        tab[i] = (10*tab[i-1]) % b;

    int temp = 0;
    for (int i=0; i<len-1; ++i){
        temp *= 10;
        temp += x[i] - 48;
        temp %= a;
        if (x[i+1] != '0' && temp == 0)
            resa.PB(i);
    }
    temp = 0;
    for (int i=len-1; i>0; --i){
        temp += (x[i]-48) * tab[len-i-1];
        temp %= b;
        // cout << temp << endl;
        if (x[i] != '0' && temp == 0)
            resb.PB(i);
    }
    /*
    for (int i=0; i<resa.size(); ++i)
     cout << ' ' << resa[i] << ' '; cout << endl;
    for (int i=0; i<resb.size(); ++i)
     cout << ' ' << resb[i] << ' '; cout << endl;
    */
    reverse(ALL(resb));
    int L = 0, R = 0;
    while (L < resa.size() && R < resb.size()){
        if (resa[L] == resb[R]-1) {
            cout << "YES\n";
            for (int i=0; i<=resa[L]; ++i)
                cout << x[i]; cout << endl;
            for (int i=resb[R]; i<len; ++i)
                cout << x[i]; cout << endl;
            return 0;
        }
        else if (resa[L] < resb[R]-1) ++L;
        else ++R;
    }
    cout << "NO\n";
}
