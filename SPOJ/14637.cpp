#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
        vector <int> arr;
        while (cin >> n) arr.push_back(n);
        sort(arr.begin(), arr.end());
        arr.push_back(0); arr.push_back(0);
        for (int i=0; i<arr.size(); i+=3)
        {
            if (arr[i]!=arr[i+1]) {cout << arr[i] << "\n"; break;}
            if (arr[i+1]!=arr[i+2]) {cout << arr[i+1] << "\n"; break;}
        }
}
