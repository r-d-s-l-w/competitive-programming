#include <iostream>
using namespace std;

void IF_EQUAL(string a, string b)
{
    if(a.length()==b.length())
        {
            int xd=0;
            for (int i=0; i<a.length(); i++)
                {
                    if (a[i]!=b[i]) {cout << "0" << endl; xd=1; break;}
                }
                if (xd==0) cout << "1" << endl;
        }
    else cout << "0" << endl;
}


int main()
{
    string a, b, znak;
    while (cin >> a >> znak >> b)
    {
        int xd=0;
        if (znak=="==") IF_EQUAL(a, b);
        else if (znak==">=")
        {
            if(a.length()>b.length()) cout << "1" << endl;
            else if (a.length()==b.length())
                {
                for (int i=0; i<a.length(); i++)
                    {
                        if (a[i]>b[i]) {cout << "1" << endl; xd=1; break;}
                    }
                    if (xd==0) IF_EQUAL(a,b);
                }
            else cout << "0" << endl;
        }

        else if (znak=="<=")
        {
            if(a.length()<b.length()) cout << "1" << endl;
            else if(a.length()==b.length())
                {
                for (int i=0; i<a.length(); i++)
                    {
                        if (a[i]<b[i]) {cout << "1" << endl; xd=1; break;}
                    }
                    if (xd==0) IF_EQUAL(a,b);
                }
            else cout << "0" << endl;
        }
        else
        {
            if(a.length()==b.length())
                {
                for (int i=0; i<a.length(); i++)
                    {
                        if (a[i]!=b[i]) {cout << "1" << endl; xd=1; break;}
                    }
                    if (xd==0) cout << "0" << endl;
                }
            else cout << "1" << endl;
        }
    }
    return 0;
}

