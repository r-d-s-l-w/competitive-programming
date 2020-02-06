#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float x[21]={0},maks=0; int y;
    string tab[21]; tab[0]="-10:|                              |", tab[1]=" -9:|                              |", tab[2]=" -8:|                              |", tab[3]=" -7:|                              |", tab[4]=" -6:|                              |", tab[5]=" -5:|                              |", tab[6]=" -4:|                              |", tab[7]=" -3:|                              |", tab[8]=" -2:|                              |", tab[9]=" -1:|                              |", tab[10]="  0:|                              |", tab[11]="  1:|                              |", tab[12]="  2:|                              |", tab[13]="  3:|                              |", tab[14]="  4:|                              |", tab[15]="  5:|                              |", tab[16]="  6:|                              |", tab[17]="  7:|                              |", tab[18]="  8:|                              |", tab[19]="  9:|                              |", tab[20]=" 10:|                              |";
    while (cin >> y) x[y+10]++;
    for (int i=0; i<21; i++) if(x[i]>maks) maks=x[i];
    for (int i=0; i<21; i++){float xd=round(x[i]*30/maks);
    for (int j=5; j<xd+5; j++)
    tab[i][j]='*';}
    for (int i=0; i<21; i++)
        cout << tab[i] << endl;
    return 0;
}
