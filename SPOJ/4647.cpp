#include <iostream>
using namespace std;

int main()
{
    int N; string txt;
    cin >> N;
    while(N--)
    {
        cin >> txt;
        for(int i=0; i<txt.length(); i++)
        {
            if(txt[i]>='A'&&txt[i]<='C') cout<<'2';
            else if(txt[i]>='D'&&txt[i]<='F') cout<<'3';
            else if(txt[i]>='G'&&txt[i]<='I') cout<<'4';
            else if(txt[i]>='J'&&txt[i]<='L') cout<<'5';
            else if(txt[i]>='M'&&txt[i]<='O') cout<<'6';
            else if(txt[i]>='P'&&txt[i]<='S') cout<<'7';
            else if(txt[i]>='T'&&txt[i]<='V') cout<<'8';
            else if(txt[i]>='W'&&txt[i]<='Z') cout<<'9';
        }
        cout << endl;
    }
    return 0;
}
