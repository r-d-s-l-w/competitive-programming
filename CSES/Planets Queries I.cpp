/// Radoslaw Mysliwiec 2020
#include <bits/stdc++.h>

using namespace std;

int n, q;
int path[200100][30];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	
	for (int i=1; i<=n; ++i)
		cin >> path[i][0];
	
	for (int i=1; i<30; ++i)
		for (int j=1; j<=n; ++j)
			path[j][i] = path[path[j][i-1]][i-1];
		
	while (q--) {
		int a, b;
		cin >> a >> b;
		
		int tmp = 29;
		while (tmp >= 0) {
			if (b >= int(1 << tmp)) {
				b -= int(1 << tmp);
				a = path[a][tmp];
			}
			--tmp;
		}
		
		cout << a << "\n";
	}
	
}
