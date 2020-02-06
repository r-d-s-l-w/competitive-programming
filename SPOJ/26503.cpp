#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int k; string pass; bool kryteria[4];
    cin >> k; cin.ignore();
    while (k--)
    {
        kryteria[0]=false; kryteria[1]=false; kryteria[2]=false; kryteria[3]=false;
        getline(cin, pass);
        if (pass.length()>7)
        {
            for (int i=0; i<pass.length(); i++)
            {
                if (pass[i]>='A'&&pass[i]<='Z') kryteria[0]=true;
                else if (pass[i]>='a'&&pass[i]<='z') kryteria[1]=true;
                else if (pass[i]>='0'&&pass[i]<='9') kryteria[2]=true;
                else kryteria[3]=true;
            }
            if (kryteria[0]==true&&kryteria[1]==true&&kryteria[2]==true&&kryteria[3]==true) cout << pass << endl;
        }
    }
}
