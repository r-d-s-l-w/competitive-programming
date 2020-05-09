/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<int> tab;

bool possible(long long time){
	long long res = 0;
	for (auto u: tab){
		res += time / u;
		if (res >= t) return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> t;
	for (int i=0; i<n; ++i){
		int temp;
		cin >> temp;
		tab.push_back(temp);
	}

	long long L = 1, R = 1e18, res;
	
	while (L <= R){
		// cout << L << ' ' << R << endl;
		long long mid = (L + R) / 2;
		if (possible(mid)) {
			R = mid - 1;
			res = mid;
		}
		else L = mid + 1;
	}
	
	cout << res << endl;

}
