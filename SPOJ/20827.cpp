#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,tab[10],xd;
    cin >> t;
    while (t--)
    {
        cin >> n; tab[2]=tab[3]=tab[4]=tab[5]=tab[6]=tab[7]=tab[8]=tab[9]=xd=0;
        if (n==0) cout << 10 << "\n";
        else if (n<10) cout << n << "\n";
        else {
            while (n%9==0) {n/=9; tab[9]++;}
            while (n%8==0) {n/=8; tab[8]++;}
            while (n%7==0) {n/=7; tab[7]++;}
            while (n%6==0) {n/=6; tab[6]++;}
            while (n%5==0) {n/=5; tab[5]++;}
            while (n%4==0) {n/=4; tab[4]++;}
            while (n%3==0) {n/=3; tab[3]++;}
            while (n%2==0) {n/=2; tab[2]++;}
            if (n!=1) cout << "NIE\n";
            else
            {
                for (int i=2; i<10; i++)
                    while(tab[i]--) cout << i;
                cout << "\n";
            }
        }
    }
}
