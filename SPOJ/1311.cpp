#include <iostream>

using namespace std;

int RzymskieNaNasze (string a) //funkcja zamienia liczbe w postaci rzymskiej do postaci int
{
    int l=a.length(), suma=0;
    for (int i=l-1; i>=0;i--)  //rzymskie oznaczenia I, V, X, L, C, D, M
    {
        if (a[i]=='I') suma++;
        else if (a[i]=='V'&&a[i-1]=='I') {suma+=4; i--;}
        else if (a[i]=='V') suma+=5;
        else if (a[i]=='X'&&a[i-1]=='I') {suma+=9; i--;}
        else if (a[i]=='X') suma+=10;
        else if (a[i]=='L'&&a[i-1]=='X') {suma+=40; i--;}
        else if (a[i]=='L') suma+=50;
        else if (a[i]=='C'&&a[i-1]=='X') {suma+=90; i--;}
        else if (a[i]=='C') suma+=100;
        else if (a[i]=='D'&&a[i-1]=='C') {suma+=400; i--;}
        else if (a[i]=='D') suma+=500;
        else if (a[i]=='M'&&a[i-1]=='C') {suma+=900; i--;}
        else if (a[i]=='M') suma+=1000;
    }
    return suma;
}

void NaszeNaRzymskie (int x) // funkcja zamienia liczbe w postaci int na postac rzymską
{
    while(x!=0)
    {
        if (x>=1000) {cout << "M"; x-=1000;}
        else if (x>=900) {cout << "CM"; x-=900;}
        else if (x>=500) {cout << "D"; x-=500;}
        else if (x>=400) {cout << "CD"; x-=400;}
        else if (x>=100) {cout << "C"; x-=100;}
        else if (x>=90) {cout << "XC"; x-=90;}
        else if (x>=50) {cout << "L"; x-=50;}
        else if (x>=40) {cout << "XL"; x-=40;}
        else if (x>=10) {cout << "X"; x-=10;}
        else if (x==9) {cout << "IX"; x-=9;}
        else if (x>=5) {cout << "V"; x-=5;}
        else if (x==4) {cout << "IV"; x-=4;}
        else if (x>=1) {cout << "I"; x-=1;}
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    string a, b;
    int x;

    while (cin >> a >> b)
    {
        x = RzymskieNaNasze(a) + RzymskieNaNasze(b);
        NaszeNaRzymskie(x); cout << "\n";
    }
    return 0;
}
