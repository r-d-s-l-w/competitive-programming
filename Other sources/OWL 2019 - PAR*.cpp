#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
using ll = long long;
 
ll tab[100000], n, q, x;
vector<ll> arr;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> tab[i];
    for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
        arr.push_back(tab[i]+tab[j]);
    sort(ALL(arr));
    cin >> q;
    while (q--){
        cin >> x;
        cout << arr[x-1] << endl;
    }
}
