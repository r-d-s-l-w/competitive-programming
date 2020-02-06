#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int x, l, xd; string nr;
    while (cin >> x)
    {

        if (x==1)
        {
            cin >> nr;
            while (nr.length()!=1)
            {
                if (nr[0]=='0') nr.erase(0,1);
                else break;
            }
            l=nr.length();
            string tab[l+2];
            tab[0]="-|||||||||||||-";
                tab[l+1]="-|||||||||||||-";
            for (int i=0; i<l; i++)
            {
                if (nr[i]=='0') tab[i+1]="-** -    *****-";
                else if (nr[i]=='1') tab[i+1]="-** -*    ****-";
                else if (nr[i]=='2') tab[i+1]="-** -**    ***-";
                else if (nr[i]=='3') tab[i+1]="-** -***    **-";
                else if (nr[i]=='4') tab[i+1]="-** -****    *-";
                else if (nr[i]=='5') tab[i+1]="-* *-    *****-";
                else if (nr[i]=='6') tab[i+1]="-* *-*    ****-";
                else if (nr[i]=='7') tab[i+1]="-* *-**    ***-";
                else if (nr[i]=='8') tab[i+1]="-* *-***    **-";
                else if (nr[i]=='9') tab[i+1]="-* *-****    *-";
            }
            for (int j=0; j<15; j++){
            for (int i=0; i<=l+1; i++)
            cout << tab[i][j]; cout << endl;}
        }
        else
        {
            bool p=false;
            string abakus[16];
            cin >> abakus[0]; cin.ignore();
            for (int i=1; i<15; i++) getline(cin, abakus[i]);
            l=abakus[0].length();
            for (int i=1; i<l-1; i++)
            {
                xd=0;
                if (abakus[2][i]==' ')  xd+=5;
                if (abakus[5][i]=='*')  xd++;
                if (abakus[6][i]=='*')  xd++;
                if (abakus[7][i]=='*')  xd++;
                if (abakus[8][i]=='*')  xd++;
                if (p==true&&xd==0||xd!=0||xd==0&&i==l-2) {cout << xd; p=true;}
            }
           cout << endl;
        }
    }
    return 0;
}
