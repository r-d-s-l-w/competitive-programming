#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int maks=0, n=0;
    int liczba,k;
    cin >> k;
    while(k--)
    {
        cin>>liczba;
        if (liczba>0||n>0){n+=liczba; if(n>maks) maks=n;}
        if (n<0) n=0;
    }
    cout << maks << endl;
}
