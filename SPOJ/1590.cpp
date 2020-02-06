#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n; ll x;
        cin >> n;
        if (n == 1) {
            cin >> x;
            cout << x << "\n";
        }
        else {
            vector <int> arr[69877];
            for (int i=0; i<n; ++i){
                cin >> x;
                arr[x%69877].push_back(x);
            }
            int xd = -1;
            for (int i=0; i<69877; ++i){
                if (arr[i].size() > n/2){
                    xd = i; break;
                }
            }
            if (xd != -1){
                for (int i=0; i<arr[xd].size() - 1; ++i){
                    if (arr[xd][i] == arr[xd][i+1]){
                        cout << arr[xd][i] << "\n";
                        break;
                    }
                }
            }
            else cout << -1 << endl;
        }
    }
}
