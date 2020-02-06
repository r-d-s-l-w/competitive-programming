#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    float m, h, BMI[t]; string name[t], nadwaga[t], niedowaga[t], norma[t];
    for (int i=0; i<t; i++)
    {
        cin >> name[i] >> m >> h;
        BMI[i]=(m*10000)/(h*h);
        if (BMI[i]<18.5) {niedowaga[i]=name[i]; norma[i]='z'; nadwaga[i]='z';}
        else if (BMI[i]>=25) {niedowaga[i]='z'; norma[i]='z'; nadwaga[i]=name[i];}
        else {niedowaga[i]='z'; norma[i]=name[i]; nadwaga[i]='z';}
    }
    cout << "niedowaga" << endl;
    for (int i=0; i<t; i++) if(niedowaga[i]!="z") cout << niedowaga[i] << endl;
    cout << "wartosc prawidlowa" << endl;
    for (int i=0; i<t; i++) if(norma[i]!="z") cout << norma[i] << endl;
    cout << "nadwaga" << endl;
    for (int i=0; i<t; i++) if(nadwaga[i]!="z") cout << nadwaga[i] << endl;
    return 0;
}
