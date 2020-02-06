#include <iostream>
#include <cmath>

using namespace std;

float liczbaPudel, M, liczbaTestow, x;
int N;

int main()
{
    cin >> liczbaTestow;
    for (int i = 0; i<liczbaTestow; i++)
    {
        x = 0;
        cin >> N >> M;
        int *tablica;
        tablica = new int [N];
        for (int j = 0; j<N; j++)
        {
            cin >> tablica[j];
            x = x + (floor(86400/tablica[j]));
        }
        cout << ceil(x/M) << endl;
    }
    return 0;
}
