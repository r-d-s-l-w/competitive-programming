#include <iostream>

using namespace std;

int t, n ,x, y;

int main()
{
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n >> x >> y;
        for(int j=2; j<n; j++)
        {
            if (j%x==0 && j%y!=0)
            {
                cout << j << " ";
            }
        }
         cout << endl;
    }
    return 0;
}
