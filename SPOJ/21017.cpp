#include <iostream>

using namespace std;

int zagadka(int a) {
    int suma=0;
    if(a==0)
        return 1;
    while(a)
    {
        int x=a%10;
        if(x==0||x==6||x==9) suma++;
        if(x==8) suma += 2;
        a/=10;
    }
    return suma;
}

int main() {
    int t, a, maks, mini;
    cin >> t;
    while(t--) {
        cin >> a;
        mini=a; maks=a;
        for(int i=0; i<5; i++)
        {
            cin >> a;
            if(maks < a) maks = a;
            if(mini > a) mini = a;
        }
        cout<<zagadka(mini)<<" "<<zagadka(maks)<<"\n";
    }
}
