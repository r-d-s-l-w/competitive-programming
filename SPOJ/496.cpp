#include <iostream>

using namespace std;

int n,D;

int main()
{
    cin>>D;
    for(int i=0;i<D;i++)
    {
    cin>>n;
    if (n<10)
    {
        int a = 1;
    for(int i=n; i!=0; i--)
    {
        a*=i;
    }
    cout << (a/10)%10 << " " << a%10 << endl;
    }
    else
    { cout << "0 0" << endl;}
    }
    return 0;
}
