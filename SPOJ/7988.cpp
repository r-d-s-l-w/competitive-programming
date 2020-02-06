#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
    int z, a, b;
    scanf("%d", &z);
    while (z--)
    {
        scanf("%d %d", &a, &b);
        if (a==b)
        {
            int x=a;
            for (int i=2; i<=sqrt(a); i++)
            if (a%i==0) {x=i; break;}
            printf("%d \n", a/x);
        }
        else {
        do
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    while(a!=b);
    printf("%d \n", a);
    }
    }
    return 0;
}
