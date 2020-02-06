#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k, n, x;
    cin >> k >> x;
    vector <int> tab(k, 0);
    for (int i=0; i<2*k; i++)
    {
        cin >> n; tab[n-1]++;
    }
    for (int i=0; i<k; i++)
    if (tab[i]%2!=0) {cout << "NIE" << endl; return 0;}
    cout << "TAK" << endl; return 0;
}
