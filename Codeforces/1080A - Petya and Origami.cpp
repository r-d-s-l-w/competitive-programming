#include <bits/stdc++.h>
 
using namespace std;
 
int tab[100100];
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    cout << ((n * 2 + k - 1) / k) + ((n * 5 + k - 1) / k) + ((n * 8 + k - 1) / k);
}
