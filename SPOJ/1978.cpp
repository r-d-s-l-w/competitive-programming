#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x; int i=0;
    while(getline(cin, x)) i++;
        cout << i;
    return 0;
}
