#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1e9+7;
 
bool comp2(vector <int> v1, vector <int> v2){
    if(v1.size()==v2.size()) return v1[0]<v2[0];
    return v1.size()>v2.size();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int s,r;
    vector <int> v[m];
    for(int i=0;i<m;i++)
        v[i].push_back(i);
    for(int i=0;i<n;i++) {
        cin>>s>>r;
        v[s-1].push_back(r);
    }
    for(int i=0;i<m;i++){
        sort(v[i].begin()+1,v[i].end());
        reverse(v[i].begin()+1,v[i].end());
    }
    for(int i=0;i<m;i++){
        int l=v[i].size();
        for(int j=2;j<l;j++)
            v[i][j]+=v[i][j-1];
    }
    ll ans=0,ansi=0;
    sort(v,v+m,comp2);
    for(int i=0;i<n;i++){
        ansi=0;
        for(int j=0;j<m;j++){
            if(i>=(v[j].size()-1)) break;
            if(v[j][i+1]>0) ansi+=v[j][i+1];
        }
        ans=max(ans,ansi);
    }
    
    cout<<ans;
    return 0;
}
