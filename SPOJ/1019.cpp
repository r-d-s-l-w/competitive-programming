#include <iostream>
using namespace std;

int main()
{
    int n, k, i, pot16[5], pot11[6], s;
    pot16[0]=1; pot16[1]=16; pot16[2]=256; pot16[3]=4096; pot16[4]=65536;
    pot11[0]=1; pot11[1]=11; pot11[2]=121; pot11[3]=1331; pot11[4]=14641; pot11[5]=161051;
    cin >> n;
    while (n--)
    {
        cin >> k;
        int xd=0, k2=k;
        for(int i=4; i>=0; i--)
        {
            if (pot16[i]<=k) {s=k/pot16[i]; if(s==10)cout<<"A"; else if(s==11)cout<<"B"; else if(s==12)cout<<"C"; else if(s==13)cout<<"D"; else if(s==14)cout<<"E"; else if(s==15)cout<<"F"; else cout<<s; k=k%pot16[i]; xd=1;}
            else if (xd==1) cout << "0";
        }
        cout << " ";
        for(int j=5; j>=0; j--)
        {
            if (pot11[j]<=k2) {s=k2/pot11[j]; if(s==10)cout<<"A"; else cout<<s; k2=k2%pot11[j]; xd=2;}
            else if (xd==2) cout << "0";
        }
        cout << endl;
    }
    return 0;
}
