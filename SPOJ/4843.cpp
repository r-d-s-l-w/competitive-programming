#include <iostream>
using namespace std;

int main()
{
    string t; int h,m, x, y[1000], k=1, b=0;
    cin>>t;
    h=(t[0]-48)*10+(t[1]-48);
    m=(t[3]-48)*10+(t[4]-48);
    y[0]=0;
    while(cin>>y[k]) k++;
        while(k--)
        {
        for(int i=0; i<2; i++)
        {
        if (i==1) x=45; else {x=y[b]; b++;}

        while (x!=0)
        {
            if (m+x>=60) {h++; x-=60;} else {m+=x; x=0;}
            if (h==24) {h=0;}
        }
        t[0]=char(h/10+48);t[1]=char(h%10+48);t[3]=char(m/10+48);t[4]=char(m%10+48);
        cout << t; if(k!=0||i!=1) cout << ",";
        }
        }
    return 0;
}
