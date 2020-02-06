#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k, a, b, xd=0;
    vector <bool> tab(1000001, true);
    vector <int> arr(1000001, 0);
    for (int i=2; i<1000; i++)
        if(tab[i]==true)
            for(int j=i+i; j<=1000000; j+=i)
                tab[j]=false;
    for (int i=2; i<=1000000; i++)
    {
        if (tab[i]==true) xd++;
        arr[i]=xd;
    }
    cin >> k;
    while (k--)
    {
        cin >> a >> b;
        cout << arr[b]-arr[a-1] << endl;
    }
    return 0;
}
