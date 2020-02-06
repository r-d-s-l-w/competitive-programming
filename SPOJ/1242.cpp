#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, licz[52]; string txt;
    cin>>n;
    for(int i=0; i<52; i++) licz[i]=0;
    for(int i=0;i<n+1;i++)
    {
        getline(cin,txt);
        for(int j=0; j<txt.length();j++)
        {
            if(txt[j]>='A'&&txt[j]<='Z') licz[txt[j]-39]++;
            else if(txt[j]>='a'&&txt[j]<='z') licz[txt[j]-97]++;
        }
    }
    for (int i=0; i<52; i++)
    {
        if(licz[i]>0&&i<26) cout << char(i+97) << " " << licz[i] << endl;
        else if(licz[i]>0&&i>=26) cout << char(i+39) << " " << licz[i] << endl;
    }
    return 0;
}
