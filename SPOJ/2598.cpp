#include <iostream>
using namespace std;

int main()
{
    string txt; int n=0;
    cin >> txt;
    for(int i=0; i<txt.length(); i++)
    {
        switch (txt[i])
        {
            case 'a': n+=1; break;
            case 'b': n+=2; break;
            case 'c': n+=3; break;
            case 'd': n+=4; break;
            case 'e': n+=5; break;
            case 'f': n+=6; break;
            case 'g': n+=7; break;
            case 'h': n+=8; break;
            case 'i': n+=9; break;
            case 'k': n+=10; break;
            case 'l': n+=20; break;
            case 'm': n+=30; break;
            case 'n': n+=40; break;
            case 'o': n+=50; break;
            case 'p': n+=60; break;
            case 'q': n+=70; break;
            case 'r': n+=80; break;
            case 's': n+=90; break;
            case 't': n+=100; break;
            case 'v': n+=200; break;
            case 'x': n+=300; break;
            case 'y': n+=400; break;
            case 'z': n+=500; break;
        }
    }
    cout << n;
    return 0;
}
