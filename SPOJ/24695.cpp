#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; string x;
    cin >> t;
    while (t--){
        cin >> x;
        int left = 0;
        int right = 0;
        if (x[0] == '|'){
            x[0] = '(';
            left++;
        }
        for (int i = 1; i < x.length(); ++i){
            if (x[i] == '|'){
                if (x[i - 1] == '(' || x[i - 1] == '-' || x[i - 1] == '+'){
                    x[i] = '(';
                    left++;
                }
                else {
                    x[i] = ')';
                    right++;
                }
            }
        }
        cout << x << endl;
    }
}
