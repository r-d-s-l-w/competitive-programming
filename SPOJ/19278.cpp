#include <iostream>
using namespace std;

int main()
{
    string D, J, M; int p=0;
    cin >> D >> J >> M;
    for (int i=0; i<D.length(); i++)
    {
        if (J[i]!=D[i]||M[i]!=D[i]) {p++; if(J[i]==M[i]) p++;}
    }
    cout << p << endl;
    return 0;
}
