#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 1'000'100'000LL

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

struct event{
	ll x,y,t,i;// 0 plant, 1 in, 2 out
};

void update(ll i, map<ll, ll> &st){
	while(i < 2*maxn){
		st[i] += 1;
		i += i&-i;
	}
}

ll query(ll i, map<ll, ll> &st){
	ll ans = 0;
	while(i){
		ans += st[i];
		i -= i&-i;
	}
	return ans;
}

bool cmp(event a, event b){
	if(a.y != b.y)
		return a.y < b.y;
	return a.x < b.x;
}

int main(){
	int p,v;
	int h=5;
	while(h--){
		cin >> p >> v;
		if(p == 0 && v == 0) break;
		vector<event> evs;
		ll x,y;
		
		for(int i = 0; i < p; i++){
			cin >> x >> y;
			x += maxn, y+=maxn;
			evs.pb({x,y,0,i});
		}

		vii pts;
		for(int i = 0; i < v; i++){
			cin >> x >> y;
			x += maxn, y+=maxn;
			pts.pb({x,y});
		}


		for(int i = 0; i < v; i++){
			x = i%v;
			y = (i+1)%v;
			if (pts[x].x != pts[y].x) continue;
			evs.pb({pts[x].x,min(pts[x].y, pts[y].y),1,i});
			evs.pb({pts[x].x,max(pts[x].y, pts[y].y),2,i});
		}

		ll ans = 0;
		map<ll, ll> st;
		sort(evs.begin(), evs.end(), cmp);
		// trace(2*maxn);
		for(auto ev: evs){
			// trace(ev.x, ev.y, ev.i, ev.t);
			if(ev.t == 0){
				// trace(ev.x, query(ev.x, st));
				if(query(ev.x, st) % 2 == 0)
					ans += ev.i+1;
			} else {
				update(ev.x, st);
			}
		}
		cout << ans << '\n';
		break;
	}
 	return 0;
}

