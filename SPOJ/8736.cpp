#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int a;
    vector <int> arr;
    while (cin>>a) arr.push_back(a);

    sort(arr.begin(), arr.end());
    arr.push_back(0);
    for (int i=0; i<arr.size(); i+=2)
        if (arr[i]!=arr[i+1]) {cout << arr[i]; break;}
}

