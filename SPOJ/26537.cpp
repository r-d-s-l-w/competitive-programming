#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int tab[n][n];
    for (int i=0; i<n; i++)
    {
        cin >> tab [i][i];
    }
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i!=j) tab[i][j]=gcd(tab[i][i],tab[j][j]);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) cout << tab[i][j] << " ";
    cout << endl;}
}
