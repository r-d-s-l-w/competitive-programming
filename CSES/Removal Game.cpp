/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

const long long INI = -1e18;
vector<vector<long long>> dp;
vector<long long> pref;
vector<int> tab;
int n;

long long solve(int L, int R){
	if (dp[L][R] != INI)
		return dp[L][R];
	if (L == R)
		return dp[L][R] = tab[L];
		
	return dp[L][R] = pref[R] - pref[L-1] - min(solve(L+1, R), solve(L, R-1));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	tab.resize(n+1);
	pref.assign(n+1, 0);
	dp.assign(n+1, vector<long long>(n+1, INI));
	
	for (int i=1; i<=n; ++i){
		cin >> tab[i];
		pref[i] = pref[i-1] + tab[i];
	}
	
	cout << solve(1, n) << endl;
	
}
