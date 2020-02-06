#include <bits/stdc++.h>

using namespace std;

struct person
{
    string name;
    string surname;
    string age;
    string pesel;
};

bool lol (person x, person y)
{
    if (x.surname != y.surname) return (x.surname < y.surname);
    if (x.name != y.name) return (x.name < y.name);
    return (x.pesel > y.pesel);
}

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int length;
    vector <person> tab;
    person x;
    while (cin >> txt)
    {
        length = txt.length();
        for (int i=0; i < length; i++)
        {
            if (txt[i] == '.')
            {
                x.name = txt.substr(i-1, 2);
                txt[i-1] = '/';
                txt[i] = '/';
                break;
            }
        }

        for (int i=0; i < length; i++)
        {
            if (txt[i]>'9'||txt[i]<'/')
            {
                int xd = 0;
                while (txt[i]>'9'||txt[i]<'/')
                {
                    xd++;
                    i++;
                    if (i == length) break;
                }
                x.surname = txt.substr(i-xd, xd);
                break;
            }
        }
        for (int i=0; i < length; i++)
        {
            int xd = 0;
            if (txt[i]>='0'&&txt[i]<='9')
            {
                while (txt[i]<='9'&&txt[i]>='0') {xd++; i++; if (i == length) break;}
                if (xd == 2) x.age = txt.substr(i-xd, 2);
                else if (xd == 11) x.pesel = txt.substr(i-xd, 11);
                else if (xd == 13 && txt[i-13] < '4') {x.pesel = txt.substr(i-11, 11); x.age = txt.substr(i-13, 2);}
                else {x.pesel = txt.substr(i-13, 11); x.age = txt.substr(i-2, 2);}
            }
        }
        tab.push_back(x);
    }
    sort(tab.begin(), tab.end(), lol);
    for (int i=0; i<tab.size(); i++)
        cout << tab[i].name << " " << tab[i].surname << " " << tab[i].age << " " << tab[i].pesel << endl;
}
