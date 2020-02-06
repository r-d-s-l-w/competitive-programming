#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k; string txt, nr;
    cin >> k;
    while (k--)
    {
        int xd=1, znak=1, x=0, l, z, left=0, right=0, number;
        cin >> txt;
        l=txt.length();
        for(int i=0;i<=l;i++)
        {
            if ((txt[i]>='0'&&txt[i]<='9')&&i!=l) x++;
            else
            {
                if (x!=0)
                {nr=txt.substr(i-x,x); x=0;number=stoi(nr);
                if (txt[i]=='x'){if (znak+xd!=0) left+=number; else left-=number;}
                else if (txt[i]=='+'){if (znak+xd!=0) right-=number; else right+=number; znak=1;}
                else if (txt[i]=='-') {if (znak+xd!=0) right-=number; else right+=number; znak=-1;}
                else if (txt[i]=='=') {if (znak+xd!=0) right-=number; else right+=number; xd=-1; znak=1;}
                else if (i==l) {if (znak+xd!=0) right-=number; else right+=number;}
                }
                else
                {if(txt[i]=='x'){if (znak*xd==1) left++; else left--;}
                else if (txt[i]=='+') znak=1;
                else if (txt[i]=='-') znak=-1;
                else if (txt[i]=='=') {xd=-1; znak=1;}
                }
            }
        }
        if(left==0) cout << "NIE" << endl;
        else cout << right/left << endl;
    }
    return 0;
    }


