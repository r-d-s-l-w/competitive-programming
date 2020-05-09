/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
int n, res;
vector<int> tab;
vector<int> dp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	tab.resize(n);
	dp.assign(n+1, INF);
	dp[0] = -INF;
	for (int i=0; i<n; ++i){
		cin >> tab[i];
	}
	
	for (int i=0; i<n; ++i){
		int temp = tab[i];
		auto it = lower_bound(dp.begin(), dp.end(), temp);
		if (*it > temp) {
			res = max(res, int(it - dp.begin()));
			*it = temp;
		}
	}
	
	cout << res << endl;
}
