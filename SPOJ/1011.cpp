#include <iostream>
using namespace std;

int main()
{
    int n; string word;
    cin >> n;
    while (n--)
    {
        cin >> word;
        for(int i=0; i<word.length()/2;i++)
            cout << word[i]; cout << endl;
    }
    return 0;
}
