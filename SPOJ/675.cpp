#include <iostream>

using namespace std;
int D, N, a, b, x=0, y=0;

int przypadki(int a, int b)
{
    switch(a)
    {
    case 0:
        x = x+b;
        break;
    case 1:
        x = x-b;
        break;
    case 2:
        y = y+b;
        break;
    case 3:
        y = y-b;
        break;
    }
}

int main()
{
    cin >> D;
    for (int i=0; i<D; i++)
    {
        cin >> N;
        for (int j=0; j<N; j++)
        {
            cin >> a >> b;
            przypadki(a, b);
        }
        if (x>0) {cout << 0 << " " << x << endl;}
        else if (x<0) {cout << 1 << " " << -x << endl;}
        if (y>0) {cout << 2 << " " << y << endl;}
        else if (y<0) {cout << 3 << " " << -y << endl;}
        else if (y==0 && x==0) {cout << "studnia" << endl;}
        x = 0; y = 0;
    }
    return 0;
}
