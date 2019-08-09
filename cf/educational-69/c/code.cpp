#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 300010
#define lgmaxn 21
const ll infll = 1e16;

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

ll val[maxn];
ll maxsp[lgmaxn][maxn];
ll minsp[lgmaxn][maxn];
int lg[maxn+1];

void initLg() {
    lg[0] = -1;
    for(int i = 1; i <= maxn; i++) lg[i] = lg[i>>1]+1;
}

void build(int n, ll sp[lgmaxn][maxn], ll fun(ll, ll)){
    for(int i=0; i<n; i++) sp[0][i] = val[i];
    for(int i=1; i <= lg[n]; i++){
        for(int j=0; j + (1<<i) <= n; j++){
            sp[i][j] = fun(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
        }
    }
}

ll query(int l, int r, ll sp[lgmaxn][maxn], ll fun(ll, ll)){
	if (r < l) return 0;
	int k = lg[r-l+1];
    return fun(sp[k][l], sp[k][r-(1<<k)+1]);
}

ll gmin(ll a, ll b){return min(a,b);}
ll gmax(ll a, ll b){return max(a,b);}
ll querymax(int l, int r) {return query(l,r,maxsp,gmax);}
ll querymin(int l, int r) {return query(l,r,minsp,gmin);}
ll query(int l, int r) {return querymax(l, r) - querymin(l, r);}

map<ii, ll> dp;

int n,z;
ll solve(int i, int k) {
	ii index = mp(i,k);
	if (dp[index]) return dp[index];
	if (k == 1) return query(i, n-1);
	dp[index] = solve(i+1, k-1);
	// trace(i,k);
	int l = i, r = n-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		// trace("here", query(i, mid), i, mid, solve(mid+1, k-1));
		if (dp[index] < query(i, mid) + solve(mid+1, k-1)) {
			r = mid-1;
		} else {
			l = mid+1;
		}
		dp[index] = min(dp[index], query(i, mid) + solve(mid+1, k-1));
	}
	return dp[index];
}

int main(){
	initLg();
	cin >> n >> z;	
	for (int i = 0; i < n; ++i)
		cin >> val[i];
	build(n, minsp, gmin);
	build(n, maxsp, gmax);
	// for (int i = 0; i < n; ++i)
	// 	for (int j = i+1; j < n; ++j)
	// 		trace(querymax(i, j), querymin(i, j));
	cout << solve(0, z) << '\n';
 	return 0;
}

