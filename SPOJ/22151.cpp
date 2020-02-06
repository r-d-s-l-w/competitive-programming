#include <iostream>
using namespace std;

int main()
{
    string txt, tab[26];
    tab[0]=".-/";tab[1]="-.../";tab[2]="-.-./";tab[3]="-../";tab[4]="./";tab[5]=".-../";tab[6]="--./";tab[7]="..../";tab[8]="../";tab[9]=".---/";tab[10]="-.-/";tab[11]="..-./";tab[12]="--/";
    tab[13]="-./";tab[14]="---/";tab[15]=".--./";tab[16]="--.-/";tab[17]=".-./";tab[18]=".../";tab[19]="-/";tab[20]="..-/";tab[21]="...-/";tab[22]=".--/";tab[23]="-..-/";tab[24]="-.--/";tab[25]="--../";
    while (getline(cin, txt))
    {
        for (int i=0; i<txt.length(); i++)
        {
            if (txt[i]>='a'&&txt[i]<='z') cout << tab[txt[i]-97];
            else if (txt[i]>='A'&&txt[i]<='Z') cout << tab[txt[i]-65];
            else cout << '/';
        }
        cout << endl;
    }
    return 0;
}
