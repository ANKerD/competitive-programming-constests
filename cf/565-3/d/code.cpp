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
#define MAXP 2750139
// #define MAXP 200010
#define maxn 200010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

bitset<MAXP> p;
int a[2*maxn];
map<int, int> go;
vi primes;

bool cmp(int &a, int &b) {
	if (p[a] != p[b])
		return p[a] < p[b];
	if (p[a])
		return a < b;
	return a > b;
}

int zero = '0';
int nine = '9';
	
void inline fastscan(int &res) {
	res = 0;
	for (char c = getchar(); c >= zero && c <= nine; c = getchar())
		res = (res<<3)+(res<<1) + (c-zero);
}

int main(){
	register int i=2;
	register int j;
	p.set();
	while (i < MAXP) {
		primes.push_back(i);
		j = i << 1;
		while (j < MAXP) {
			p[j] = 0;
			go[j] = max(go[j], j/i);
			j += i;
		}
		++i;
		while (i < MAXP && !p[i])
			++i;
	}
	int n;
	fastscan(n);
	map<int, int> f;
	for (i = 0; i < 2*n; ++i) {
		fastscan(a[i]);
		++f[a[i]];
	}	
	sort(a,a+2*n, cmp);
	vi ans;
	for (i = 0; i < 2*n; i++) {
		if (!f[a[i]]) continue;
		
		if (p[a[i]] && f[primes[a[i]-1]]) {
			ans.pb(a[i]);
			--f[a[i]];
			--f[primes[a[i]-1]];
			continue;
		}
		if (f[go[a[i]]]) {
			ans.pb(a[i]);
			--f[go[a[i]]];
			--f[a[i]];
		}
	}

	for (int i = 0; i < ans.size(); ++i)
		printf("%d%c", ans[i], " \n"[i+1==ans.size()]);

 	return 0;
}

