#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, s, sum = 0;
    cin >> n >> s;
    sum += s/n;
    if (s%n != 0) sum++;
    cout << sum;
}
