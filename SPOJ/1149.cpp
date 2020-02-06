#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int D,N,x;
    cin >> D;
    while (D--)
    {
        vector <int> pkt;
        cin >> N;
        while(N--)
        {
            cin>>x;
            pkt.push_back(x);
        }
        int key, i;
        for(int j=1; j<pkt.size();j++)
        {
            key=pkt[j];
            i=j-1;
            while(i>=0&&pkt[i]>key)
            {
                pkt[i+1]=pkt[i];
                i--;
            }
            pkt[i+1]=key;
        }
        int l=2;
        cout << pkt[pkt.size()-1] << " ";
        while (pkt[pkt.size()-l]==pkt[pkt.size()-1]&&l<pkt.size()) {cout << pkt[pkt.size()-l] << " "; l++;}
        if(pkt.size()!=1){for(int i=0; i<=pkt.size()-l; i++) cout << pkt[i] << " ";} cout << endl;
    }
    return 0;
}
