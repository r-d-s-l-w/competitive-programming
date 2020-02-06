#include <iostream>
#include <algorithm>

using namespace std;

#define toInt(a) ((a)-'0')
#define toChar(a) ((char)((a)+'0'))

bool palindrome(string s)
{
    for (int i=1; i<s.length(); i++)
    {
        if (s[i-1] != s[s.length()-i]) return false;
    }
    return true;
}

void addStrings(string& a, string& b)
{
    if (a.length() < b.length()) {string temp = a; a=b; b=temp;}
    int x = 0;
    for (unsigned long i = 1; i <= a.length(); i++)
    {
        int b1 = 0;
        if (i <= b.length()) {b1 = toInt(b[b.length()-i]);}
        int r = toInt(a[a.length()-i]) + b1 + x;
        x = r/10;
        a[a.length()-i] = toChar(r%10);
    }
    if (x!=0)
        a = toChar(x) + a;
}

int main()
{
    int t, ile;
    cin >> t;
    string s, sr;
    for (int i = 0;i < t; i++)
    {
        ile=0;
        cin >> s;
        while (!palindrome(s))
        {
            ile++;
            sr = s;
            reverse (sr.begin(), sr.end());
            addStrings(s, sr);
        }
        cout << s << " " << ile << endl;
    }


return 0;
}
