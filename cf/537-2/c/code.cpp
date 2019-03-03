#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2147483648
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

map<ll, ll> m;
void update(ll i){

	for(; i < maxn; i+=i&-i){
		// if(i)
		// 	trace1(i);
		m[i]+=1;
	}
}
ll query(int i){
	ll ret=0;
	for(; i; i-=i&-i)ret+=m[i];
	return ret;
}
ll query(ll a, ll b){
	return query(b)-query(a-1);
}
//map<ii,ll> dp;
int n,k,a,b;
ll solve(int l, int r){
	if(l>r) return 0;

	int tam = query(l,r);
	if(!tam) return a;
	if(l==r){
		if(tam) return b*tam;
		return a;
	}

	int mid = (l+r)>>1;
	return min((ll(r-l+1))*b*tam,solve(l,mid)+solve(mid+1,r));
}

int main(){
	int x;
	cin >> n >> k >> a >> b;
	for(int i = 0; i < k; i++){
		cin >> x;
		update(x);
	}
	trace1(solve(1,(1<<n)));
 	return 0;
}
