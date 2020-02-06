#include <bits/stdc++.h>

using namespace std;

int tab[5000][5000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, xd=0, next = 0;
    cin >> a;
    for (int i=0; i<=a; ++i){
        for (int j=0; j<xd; ++j){
            ++next;
            tab[xd-j][j] = next;
            if (next == a) break;
        }
        xd++;
        if (next == a) break;
    }
    for (int i=xd-1; i>0; --i){
        for (int j=0; j<xd; ++j) {if (tab[i][j]) cout << tab[i][j] << ' ' ; else cout << "  "; }cout << endl;}

}
