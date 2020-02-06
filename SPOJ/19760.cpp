#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m, x, i=0, j=0;
    vector <int> a;
    vector <int> b;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for (int i=0; i<m; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long int mini = 2000000000;
    while (i < n && j < m)
    {
        if (a[i] > b[j])
        {
            if (a[i] - b[j] < mini) mini = a[i] - b[j];
            j++;
        }
        else if (a[i] < b[j])
        {
            if (b[j] - a[i] < mini) mini = b[j] - a[i];
            i++;
        }
        else
        {
            mini = 0; break;
        }
    }

    cout << mini;
}
