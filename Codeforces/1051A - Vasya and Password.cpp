#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    string s; int t;
    cin >> t;
    while (t--)
    {
        cin >> s;
        bool mala = 0, duza = 0, cyfra = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]>='A'&&s[i]<='Z') duza = 1;
            else if (s[i]>='a'&&s[i]<='z') mala = 1;
            else if (s[i]>='0'&&s[i]<='9') cyfra = 1;
        }
        if (mala*duza*cyfra==1) cout << s << "\n";
        else{
            if (duza+mala+cyfra==1)
            {
                if (duza==0 && mala==0) {s[0]='A'; s[1]='a';}
                else if (mala==0 && cyfra==0) {s[0]='a'; s[1]='0';}
                if (cyfra==0 && duza==0) {s[0]='0'; s[1]='A';}
            }
            else if (duza+mala+cyfra==2)
            {
                int d=0, m=0, c=0;
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i]>='A'&&s[i]<='Z')
                    {
                        d++;
                        if (d>1){
                        if (duza==0&&d>1) s[i]='A';
                        else if (mala==0) s[i]='a';
                        else if (cyfra==0) s[i]='0';
                        break;}
                    }
                    else if (s[i]>='a'&&s[i]<='z')
                    {
                        m++;
                        if (m>1){
                        if (duza==0) s[i]='A';
                        else if (mala==0) s[i]='a';
                        else if (cyfra==0) s[i]='0';
                        break;}
                    }
                    else if (s[i]>='0'&&s[i]<='9')
                    {
                        c++;
                        if (c>1){
                        if (duza==0) s[i]='A';
                        else if (mala==0) s[i]='a';
                        else if (cyfra==0) s[i]='0';
                        break;}
                    }
                }
            }
            cout << s << "\n";
        }
    }
}
