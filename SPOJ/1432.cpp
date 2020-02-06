#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int arr[5], t, s, tab[25], xd; bool TorF[5]; arr[0]=127; arr[1]=131; arr[2]=137; arr[3]=139; arr[4]=149;
    cin >> t;
    while (t--)
    {
        cin >> s; xd=0;
        for (int i=0; i<s; i++)
            cin >> tab[i];
        for (int j=0; j<5; j++)
        {
            TorF[j]=true;
            for (int i=0; i<s; i++)
                if (tab[i]%arr[j]>90||tab[i]%arr[j]<65) TorF[j]=false;
            if (TorF[j]==true) xd++;
        }
        if (xd!=1) cout << "NIECZYTELNE\n";
        else
        {
            for (int i=0; i<5; i++)
                if (TorF[i]==true) {cout << arr[i] << " "; xd=i;}
            for (int i=0; i<s; i++)
                cout << char(tab[i]%arr[xd]); cout << endl;
        }
    }

    return 0;
}
