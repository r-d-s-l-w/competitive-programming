#include <iostream>
using namespace std;

int main()
{
    long long int n;
    while (cin >> n)
    {
        long long int k=0, N=1, d=1;
        while (N<n)
        {
            N+=d;
            d++;
            k++;
        }
        cout << k << endl;
    }
    return 0;
}
