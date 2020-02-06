//Radek M
#include <iostream>
using namespace std;

int main()
{
    int n, x, xd=0, y; string txt;
    cin >> n >> txt;
    x=txt.length();
    y=x;
    if (y<=n) {cout << txt; return 0;}
    for (int i=y-1; i>=0; i--)
    {
        if (x==n) break;
        else if (((90 < txt[i] || txt[i] < 65) && (122 < txt[i] || txt[i] < 97) && (57 < txt[i] || txt[i] < 48) && txt[i] != 36)){txt[i]='*';x--;}
    }
    for (int i=y-1; i>=0; i--)
    {
        if (x==n) break;
        else if (txt[i]>='0'&&txt[i]<='9') {txt[i]='*';x--;}
    }
    for (int i=0; i<y; i++)
    {
        if (x==n) break;
        else if ((txt[i]=='A'||txt[i]=='E'||txt[i]=='I'||txt[i]=='U'||txt[i]=='Y'||txt[i]=='O'||txt[i]=='a'||txt[i]=='e'||txt[i]=='i'||txt[i]=='u'||txt[i]=='y'||txt[i]=='o')&&xd==1) {txt[i]='*'; x--;}
        else if (txt[i]=='A'||txt[i]=='E'||txt[i]=='I'||txt[i]=='U'||txt[i]=='Y'||txt[i]=='O'||txt[i]=='a'||txt[i]=='e'||txt[i]=='i'||txt[i]=='u'||txt[i]=='y'||txt[i]=='o') xd=1;
    }
    for (int i=y-1; i>=0; i--)
    {
        if (x==n) break;
        else if (txt[i]!='*'&&xd==2) {txt[i]='*'; x--;}
        else if (txt[i]!='*') xd=2;
    }
    for (int i=0; i<y; i++)
    {
        if (txt[i]!='*') cout << txt[i];
    }
    return 0;
}
