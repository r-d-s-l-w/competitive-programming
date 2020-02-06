#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >>n;
    if (n==2||n==1) cout << "NIE" << endl;
    else if (n==0) cout << "0" << endl;
    else if (n==3) cout << "1 3 0 2" << endl;
    else {
            if (n%2==0){
            for (int i=0; i<=n/2; i++) cout << i*2 << " ";
            for (int i=0; i<n/2; i++) cout << i*2+1 << " "; cout << endl;}
            else {for (int i=0; i<=n/2; i++) cout << i*2 << " ";
            for (int i=0; i<=n/2; i++) cout << i*2+1 << " "; cout << endl;}
        }
    return 0;
}
