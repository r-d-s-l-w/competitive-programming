#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    double c, k ,w;
    while(t--)
    {
        cin>>c>>k>>w;
        if(c*w>k) cout << "no" << endl;
        else cout << "yes" << endl;
    }
    return 0;
}
