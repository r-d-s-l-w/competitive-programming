#include <iostream>
using namespace std;

int main()
{
    int T, n ,k;
    cin >> T;
    while (T--)
    {
        long long result = 1;
        cin >> n >> k;
        if (2*k > n) k = n - k;
        if (n == k || k == 0) cout << 1 << endl;
        else {
        	for (int i = 1; i <= k; ++i) 
        		result = result * (n - i + 1) / i;
        	cout << result << endl;
        }
    }
    return 0;
}
