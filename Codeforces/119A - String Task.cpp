#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    string txt;
    cin >> txt;
    transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
    for (int i=0; i<txt.length(); i++) if (txt[i]!='a'&&txt[i]!='o'&&txt[i]!='y'&&txt[i]!='e'&&txt[i]!='u'&&txt[i]!='i') cout << '.' << txt[i];
}
