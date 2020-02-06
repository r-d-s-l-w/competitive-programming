#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    long long int r, k, x, n, R;
    cin >> k;
    while (k--)
    {
        cin >> r;
        x=0; n=0; R=r*r;
        while(r!=0)
        {
            if(R>=r*r+x*x) {n+=r; x++;}
            else r--;
        }
        cout << 4*n+1 << endl;
    }
}
