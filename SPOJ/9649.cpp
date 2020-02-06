#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string kod, pesel; int x, y, dni, xd, kontrol, cyfra, rok, tab[]={9,7,3,1}, poprawne=0; bool hehe;
    cin >> kod >> x;
    while (x--)
    {
        cin >> pesel; xd=-1; kontrol=cyfra=dni=rok=0; hehe=true;
        for (int i=0; i<10; i++)
        {
            if (pesel[i]=='?') xd=i;
            else kontrol+=tab[i%4]*(pesel[i]-48);
        }
        if (xd!=-1)
        {
            while (kontrol%10!=pesel[10]-48)
            {
                kontrol+=tab[xd%4];
                cyfra++;
            }
            pesel[xd]=cyfra+48;
        }
        if (pesel[2]<'2') rok+=1900;
        else if (pesel[2]<'4') rok+=2000;
        else if (pesel[2]<'6') rok+=2100;
        else if (pesel[2]<'8') rok+=2200;
        else rok+=1800;
        rok+=(pesel[0]-48)*10+(pesel[1]-48);
        if (kod[0]!='0')
        {
            if(pesel[9]%2!=kod[0]%2) hehe=false;
        }
        if (kod[2]!='0'&&hehe==true)
        {
            if (((rok%4==0&&rok%100!=0)||rok%400==0)&&kod[2]=='2') hehe=false;
            else if (((rok%4!=0||rok%100==0)&&rok%400!=0)&&kod[2]=='1') hehe=false;
        }
        if (kod[1]!='0'&&hehe==true)
        {
            dni+=(pesel[4]-48)*10+(pesel[5]-48);
            y=((pesel[2]-48)*10+(pesel[3]-48))%20;
            if (y==2) dni+=31;
            else if (y==3) dni+=59;
            else if (y==4) dni+=90;
            else if (y==5) dni+=120;
            else if (y==6) dni+=151;
            else if (y==7) dni+=181;
            else if (y==8) dni+=212;
            else if (y==9) dni+=243;
            else if (y==10) dni+=273;
            else if (y==11) dni+=304;
            else if (y==12) dni+=334;
            if ((rok%4==0&&rok%100!=0||rok%400==0)&&y>2) dni++;
            rok-=1800;
            dni+=rok*365+(rok-1)/4;
            if (rok>100) dni--;
            if (rok>300) dni--;
            if (rok>400) dni--;
            if ((dni+1%7)%7!=kod[1]-49) hehe=false;
        }
        if (hehe==true) poprawne++;
    }
    cout << poprawne;
}
