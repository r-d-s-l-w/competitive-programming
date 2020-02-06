#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t, a[3]; string color;
    cin >> t;
    while (t--)
    {
        color="#";
        for (int i=0; i<3; i++)
        {
            cin >> a[i];
            if (a[i]/16==10) color+="A";
            else if (a[i]/16==11) color+="B";
            else if (a[i]/16==12) color+="C";
            else if (a[i]/16==13) color+="D";
            else if (a[i]/16==14) color+="E";
            else if (a[i]/16==15) color+="F";
            else color+=char(48+a[i]/16);
            if (a[i]%16==10) color+="A";
            else if (a[i]%16==11) color+="B";
            else if (a[i]%16==12) color+="C";
            else if (a[i]%16==13) color+="D";
            else if (a[i]%16==14) color+="E";
            else if (a[i]%16==15) color+="F";
            else color+=char(48+a[i]%16);
        }
        if (color=="#000000") cout << "black" << "\n";
        else if (color=="#C0C0C0") cout << "silver" << "\n";
        else if (color=="#808080") cout << "gray" << "\n";
        else if (color=="#FFFFFF") cout << "white" << "\n";
        else if (color=="#800000") cout << "maroon" << "\n";
        else if (color=="#FF0000") cout << "red" << "\n";
        else if (color=="#800080") cout << "purple" << "\n";
        else if (color=="#FF00FF") cout << "fuchsia" << "\n";
        else if (color=="#008000") cout << "green" << "\n";
        else if (color=="#00FF00") cout << "lime" << "\n";
        else if (color=="#808000") cout << "olive" << "\n";
        else if (color=="#FFFF00") cout << "yellow" << "\n";
        else if (color=="#000080") cout << "navy" << "\n";
        else if (color=="#0000FF") cout << "blue" << "\n";
        else if (color=="#008080") cout << "teal" << "\n";
        else if (color=="#00FFFF") cout << "aqua" << "\n";
        else cout << color << "\n";
    }
}
