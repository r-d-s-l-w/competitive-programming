#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

int T, n;
int tab[10100];
int arr[10100];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> tab[i];

        int a = 0, b = 0, it = 0;
        int A = 0, B = 0, res = 0;

        for (int i=0; i<n; ++i){
            if (tab[i] == a) ++A;
            else if (tab[i] == b) ++B;
            else if (!a) {
                a = tab[i]; ++A;
            }
            else if (!b){
                b = tab[i]; ++B;
            }
            else {
                while(A != 0 && B != 0){
                    if (tab[it] == a) --A;
                    else --B;
                    ++it;
                }
                if (!A) {
                    a = tab[i]; ++A;
                }
                else {
                    b = tab[i]; ++B;
                }
            }
            res = max(res, A+B);
        }
       cout << res << '\n';
    }
}
