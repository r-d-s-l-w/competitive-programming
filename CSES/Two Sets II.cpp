/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> dp;
const long long MOD = 1e9 + 7;
int n;

long long pow(long long a, long long b, long long c) {
	if (b == 0) return 1;
	
	long long temp = pow(a, b/2, c);
	
	if (b % 2 == 0) return (temp * temp) % c;
	
	return (((temp * temp) % c) * a) % c;
}

long long odwrotnosc(long long a, long long p) {
	// a^(p - 1) = 1 (mod p) => a^(p-2) = a^(-1) (mod p)
	return pow(a, p-2, p);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	int sum = (n * (n+1)) / 2;
	
	if (sum % 2){
		cout << 0 << endl;
		return 0;
	}
	
	dp.assign(n+1, vector<long long>(sum/2 + 1, 0));
	dp[0][0] = 1;
	
	for (int i=1; i<=n; ++i){
		for (int j=0; j<=sum/2; ++j){
			dp[i][j] += dp[i-1][j];
			if (j >= i) dp[i][j] += dp[i-1][j - i];
			
			while (dp[i][j] >= MOD) {
				dp[i][j] -= MOD;
			} 
		}
	}
	
	cout << (dp[n][sum/2] * odwrotnosc(2, MOD)) % MOD << endl;
	
}
