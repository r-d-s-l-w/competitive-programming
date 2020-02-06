#include <iostream>

using namespace std;

int a,b,t;
int nwd(int a,int b)
{
    while(a!=b)
{
    if(a>b)
    {
        a-=b;
    }

    else if(b>a)
    {
        b-=a;
    }

}
return a;
}

int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
    cin>>a>>b;
    cout<<nwd(a,b)<<endl;
    }
    return 0;
}
