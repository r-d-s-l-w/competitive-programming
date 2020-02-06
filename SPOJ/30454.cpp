#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define inf 0x3f3f3f3f

#define PI acos(-1)
#define eps 1e-9
//#define inf 100000000
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


#define ll long long int
#define ff first
#define ss second
#define sc(a)           scanf("%d", &a)
#define sc2(a, b)       scanf("%d%d", &a, &b)
#define sc3(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define SS(a) scanf("%lli", &a)
#define P(a) printf("%i", a)
#define PP(a) printf("%lli", a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

ll mod = 1000000007;

ll x1, x2, yy, y2, fx, fy;

ll fact[200002], ifact[200002];

ll power(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll x = power(b, p/2);
    x = (x*x)%mod;

    if (p%2 == 0)
        return x;
    else return (b*x)%mod;
}

int main()
{
	int t, cs = 0;
	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
	for(int i = 2; i <= 200000; i++){
		fact[i] = (1LL*fact[i-1]  * i ) % mod;
		ifact[i] = (1LL*ifact[i-1] * power(i, mod-2)) % mod;
	}
	sc(t);
	while(t--){
		SS(x1); SS(yy); SS(x2); SS(y2);
		fx = x2 - x1;
		fy = y2 - yy;
		ll p = fx + fy;
		ll ans = 0;
		for(int i = 0; i <= min(fx, fy); i++){
			ll k = 1;
			k *= (1LL * ( (fact[p-i]  * ifact[p-i-fx]) % mod) * ifact[fx] ) % mod;
			k *= (1LL * ( (fact[fx] * ifact[fx-i]) % mod) * ifact[i]) % mod;
			ans += k;
			ans %= mod;
		}
		printf("Case %i: %lli\n", ++cs, ans);
	}
}
