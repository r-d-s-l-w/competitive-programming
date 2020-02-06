#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int t,n,a;
    cin >> t;
    while (t--)
    {
        vector <int> arr;
        cin >> n;
        while (n--)
        {
            cin >> a;
            arr.push_back(a);
        }
        sort(arr.begin(), arr.end());
        arr.push_back(0);
        for (int i=0; i<arr.size(); i+=2)
            if (arr[i]!=arr[i+1]) {cout << arr[i] << "\n"; break;}
    }
}
