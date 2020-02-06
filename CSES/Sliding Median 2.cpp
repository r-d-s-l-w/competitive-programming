/// Radoslaw Mysliwiec 2020
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'
#define dd cout << " debug";
 
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int,int>;
using pll = pair<ll,ll>;
using matrix = vector<vll>;
 
priority_queue<pi> below;
priority_queue<pi, vector<pi>, greater<pi>> above;
int n, k, below_size, above_size;
vi which_one(200200, 0);
 
int get_median(){
    if (below.empty()) return -1;
    return below.top().F;
}
 
void prepare(){
    while(!below.empty() && which_one[below.top().S] != 1)
        below.pop();
    while(!above.empty() && which_one[above.top().S] != 2)
        above.pop();
 
    while(below_size > above_size + 1){
        which_one[below.top().S] = 2;
        above.push(below.top()); ++above_size;
        below.pop(); --below_size;
    }
 
    while(below_size < above_size){
        which_one[above.top().S] = 1;
        below.push(above.top()); ++below_size;
        above.pop(); --above_size;
    }
 
    while(!below.empty() && which_one[below.top().S] != 1)
        below.pop();
    while(!above.empty() && which_one[above.top().S] != 2)
        above.pop();
}
 
void add(int x, int it){
    if (!below.empty() && pi{x, it} > below.top()){
        above.push({x, it});
        which_one[it] = 2;
        ++above_size;
    }
    else {
        below.push({x, it});
        which_one[it] = 1;
        ++below_size;
    }
    prepare();
}
 
void del(int it){
    which_one[it] == 1 ? --below_size : --above_size;
    which_one[it] = 0;
    prepare();
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> k;
    int tmp = 1;
    for (int i=1; i<=n; ++i){
        int a; cin >> a;
        add(a, i);
        if (i - tmp >= k - 1){
            cout << get_median() << ' ';
            del(tmp);
            ++tmp;
        }
    }
}
