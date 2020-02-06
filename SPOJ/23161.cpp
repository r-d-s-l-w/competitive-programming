#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt1, txt2; int k, t;
    long long int tab1[26], tab2[26], temp[26];
    cin >> t;
    while (t--)
    {
        for (int i=0; i<26; i++) {tab1[i] = 0; tab2[i] = 0;}
        cin >> txt1 >> txt2 >> k;
        for (int i=0; i<txt1.length(); i++) tab1[txt1[i]-97]++;
        for (int i=0; i<txt2.length(); i++) tab2[txt2[i]-97]++;
        for (int i=1; i<k; i++)
        {
            for (int j=0; j<26; j++)
            {
                temp[j] = tab2[j];
                tab2[j] += tab1[j];
                tab1[j] = temp[j];
            }
        }
        for (int i=0; i<26; i++) cout << tab1[i] << " "; cout << endl;
    }
}
