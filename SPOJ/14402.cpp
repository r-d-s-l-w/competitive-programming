#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned long long int x, y, a, pages;
    while (cin>>x)
    {
        a=1; y=9; pages=0;
        while (x!=0)
        {
            if (x>a*y)
            {
                pages+=y;
                x-=a*y;
                y*=10; a++;
            }
            else
            {
                pages+=x/a;
                x=0;
            }
        }
        cout << pages << endl;
    }
}
