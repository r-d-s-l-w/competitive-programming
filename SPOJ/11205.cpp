#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    while (k--)
    {
    int p,s, xd1=32400, xd2=0,ile=0, maks=0, hour, m, sec; string txt, x, y;
    cin >> p >> x;
    s=(x[0]-48)*36000+(x[1]-48)*3600+(x[3]-48)*600+(x[4]-48)*60+(x[6]-48)*10+(x[7]-48);
    while (p--)
    {
        cin >> txt >> y;
        if (y=="AC")
        {
            xd2=(txt[0]-48)*36000+(txt[1]-48)*3600+(txt[3]-48)*600+(txt[4]-48)*60+(txt[6]-48)*10+(txt[7]-48);
            if (xd2-xd1>s) {if (xd2-xd1-s>maks) maks=xd2-xd1-s;}
            xd1=xd2;
        }
    }
    if (xd2+s<50400&&xd2!=0) {if (50400-xd2-s>maks) maks=50400-xd2-s;}
    else if (s<18000&&xd2==0) maks=18000-s;
    if (maks!=0) {hour=maks/3600; maks-=hour*3600; m=maks/60; maks-=m*60; sec=maks;
    if (hour<10) cout << 0 << hour << ':';
    else cout << hour << ':';
    if (m<10) cout << 0 << m << ':';
    else cout << m << ':';
    if (sec<10) cout << 0 << sec << endl;
    else cout << sec << endl;}
    else cout << 0 << endl;
}
}
