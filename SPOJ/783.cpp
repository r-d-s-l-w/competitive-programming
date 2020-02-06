#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool czyWieksza(string a, string b)
{
	int l=a.length(), L=b.length();
	if (l!=L) return l>L;
	else
	{
		int i=0;
		while(a[i]==b[i]&&i<l) i++;
		return a[i]>b[i];
	}
}
bool czyMniejsza(string a, string b)
{
    int l=a.length(), L=b.length();
    if (l!=L) return l<L;
    else
    {
        int i=0;
        while (a[i]==b[i]&&i<l) ++i;
        return a[i]<b[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    unsigned int n, k; int l; string x;
    cin >> n;
    vector <string> tab(n);
    for (int i=0; i<n; i++)
        cin >> tab[i];
    sort(tab.begin(), tab.end(), czyMniejsza);
    cin >> k; l=tab.size();
    while (k--)
    {
        cin >> x;
        int low=0, high=l-1; bool xd=false;
        if (czyWieksza(x,tab[high])) cout << high+1 << endl;
        else {
        while (low<=high)
        {
            int mid=(low+high)/2;
            if (czyWieksza(tab[mid],x)) high=mid-1;
            else if (czyMniejsza(tab[mid],x)&&czyMniejsza(tab[mid+1],x)) low=mid+1;
            else if (tab[mid]==x) high=mid-1;
            else {cout << mid+1 << endl; xd=true; break;}
        }
        if (xd==false) cout << 0 << endl;
        }
    }
    return 0;
}
