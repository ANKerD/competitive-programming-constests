#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<ll, ll>
#define vi vector<ll>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 100010
#define vo vector<order>
#define pqll priority_queue<ll, vll, greater<ll> > 

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

struct order {
	ll t,d,i, fin, own;
};

struct resp {
	ll i, fin, own;
};

bool inline operator < (const order &a, const order &b) {
	return a.t < b.t;
};

order p[maxn];

ll n,k;
void solve(pqll &q, ll &l, vector<resp> &ans, ll owner, ll i, ll j){
	order top = p[j];
	
	ll wait = top.d;
	ll arrive = top.t;
	
	// trace(i, l, owner);
	l = max(l, arrive)+wait*owner;
	q.push(l);
	ans.pb({i, l, owner});
}

bool cmp(resp &a, resp &b){
	// trace(a.i, b.i);
	return a.i < b.i;
}

int main(){
	cin >> n >> k;
	// trace(n,k);
	for(register ll i = 0; i < n; ++i){
		register ll x;
		register ll y;
		cin >> x >> y;
		p[i] = {x,y,i,-1, -1};
	}

	stable_sort(p,p+n);


	pqll pa, pb;
	vector<resp> ans;
	ll la=0, lb=0;

	for (register ll i = 0; i < n; ++i){
		while(!pa.empty() && pa.top() <= p[i].t)
			pa.pop();
		while(!pb.empty() && pb.top() <= p[i].t)
			pb.pop();
		
		// for (register ll i = 0; i < n; ++i)
		// 	trace(p[i].t,p[i].d,p[i].i,p[i].fin,p[i].own);
		// trace("der");

		if (pa.size() <= pb.size())
			solve(pa, la, ans,1, p[i].i, i);
		else
			solve(pb, lb, ans,k, p[i].i, i);
	}

	// while(!pa.empty()){
	// 	trace(pa.top());
	// 	pa.pop();
	// }

	sort(ans.begin(), ans.end(), cmp);

	for (register ll i = 0; i < n; ++i) {
		char c = ans[i].own == 1? 'A':'B';
		ll tuu = ans[i].fin;
		printf("%c %lld\n", c, tuu);
	}	

 	return 0;
}

