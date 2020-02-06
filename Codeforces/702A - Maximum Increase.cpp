#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
 
int n;
int tab[100100];
int maxx = 1, temp = 1;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> tab[i];
    for (int i=1; i<n; ++i){
        if (tab[i] > tab[i-1]) ++temp;
        else temp = 1;
        maxx = max(maxx,temp);
    }
    cout << maxx << endl;
}
