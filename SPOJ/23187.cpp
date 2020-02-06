#include <iostream>
using namespace std;
int F (char x, char y)
{
    if (x=='0') if (y=='0') return 1; else return 0;else if(x=='1') if (y=='1') return 1; else return 0;else if(x=='2') if (y=='2'||y=='A'||y=='B'||y=='C'||y=='a'||y=='b'||y=='c') return 1; else return 0;else if(x=='3') if (y=='3'||y=='D'||y=='E'||y=='F'||y=='d'||y=='e'||y=='f') return 1; else return 0;else if(x=='4') if (y=='4'||y=='G'||y=='H'||y=='I'||y=='g'||y=='h'||y=='i') return 1; else return 0;else if(x=='5') if (y=='5'||y=='J'||y=='K'||y=='L'||y=='j'||y=='k'||y=='l') return 1; else return 0;else if(x=='6') if (y=='6'||y=='M'||y=='N'||y=='O'||y=='m'||y=='n'||y=='o') return 1; else return 0;else if(x=='7') if (y=='7'||y=='P'||y=='Q'||y=='R'||y=='S'||y=='p'||y=='q'||y=='r'||y=='s') return 1; else return 0;else if(x=='8') if (y=='8'||y=='T'||y=='U'||y=='V'||y=='t'||y=='u'||y=='v') return 1; else return 0;else if(x=='9') if (y=='9'||y=='W'||y=='X'||y=='Y'||y=='Z'||y=='w'||y=='x'||y=='y'||y=='z') return 1; else return 0;else return 0;
}
int main()
{
    int t,xd;string x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y; xd=0;
        for (int i=0;i<y.length();i++)
        if(F(y[i],x[i])==0){cout<<"NIE\n";xd=1;break;}
        if(xd==0)cout<<"TAK - "<<x<< endl;
    }
    return 0;
}
