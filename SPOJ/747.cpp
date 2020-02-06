#include <iostream>
#include <vector>

using namespace std;

unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

unsigned long long int lcm(unsigned long long int a, unsigned long long int b)
{
    unsigned long long int temp = gcd(a, b);

    return (a/temp*b);
}

int main()
{
    unsigned long long int k, n, x;
    vector <unsigned long long int> tab;
    cin >> k;
    while (k--)
    {
        cin >> n;
        while (n--)
        {
            cin >> x;
            tab.push_back(x);
        }
        for (int i=1; i<tab.size(); i++)
            tab[0]=lcm(tab[0], tab[i]);
        cout << tab[0] << endl;
        tab.clear();
    }
    return 0;
}
