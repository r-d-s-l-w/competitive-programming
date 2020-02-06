#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int guess[4], nr[4], c, n=1;
int main()
{
    while (c!=4&&n<11)
    {
    c=0;
    for (int i=0; i<4; i++) cout << n <<" "; cout << endl << flush;
    for (int i=0; i<4; i++) cin >> nr[i];
    for (int i=0; i<4; i++) if (nr[i]==1) guess[i]=n;
    if (n==6) {cout << guess[0] << " " << guess[1] << " " << guess[2] << " " << guess[3] << endl; break;}
    n++;
    }
    return 0;
}
