#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    string txt; int n, k, l;
    cin >> txt >> n; l=txt.length();
    while (n--)
    {
        cin >> k;
        if (k>0)
        {
            cout << txt[0];
            for (int i=1; i<l; i++){
                 for(int j=0; j<k-1; j++) cout << ' '; cout << txt[i];}
        }
        else if (k<0)
        {
            k*=-1; cout << txt[l-1];
            for (int i=l-2; i>=0; i--){
                for(int j=0; j<k-1; j++) cout << ' '; cout << txt[i];}
        }
        else cout << txt[l-1];
        if (n!=0) cout << endl;
    }
    return 0;
}
