#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
#define ll long long

struct ln{
	ll x1,x2,y;
};

struct pt {
	ll x,y;
};

struct event {
	ll x,y,d,t;
};

ll n;
pt pivot;
ln lines[maxn];

void rotate(ln &line){
	ll x1 = 2*pivot.x - line.x1;
	ll x2 = 2*pivot.x - line.x2;
	ll  y = 2*pivot.y - line.y;
	line = {x2, x1, y};
}

ll ccw(event a, event b){
	pt p1 = {a.x - pivot.x, a.y - pivot.y};
	pt p2 = {b.x - a.x, b.y - a.y};
	return p1.x*p2.y - p1.y*p2.x;
}

bool cmp(event a, event b){
	ll xw = ccw(a,b);
	if(xw == 0) return a.t > b.t;
	return xw < 0;
}

ll resolve(){
	vector<event> events;
	for(ll i = 0; i < n; i++){
		if(lines[i].y == pivot.y) continue;
		ln lne = lines[i];
		if(lne.y > pivot.y)	
			rotate(lne);
		event e1 = {lne.x1, lne.y, lne.x1-lne.x2, 0}; // 0 entrada
		event e2 = {lne.x2, lne.y, lne.x2-lne.x1, 1}; // 1 saida
		assert(lne.x1 <= lne.x2);
		assert(lne.y < pivot.y);
		events.push_back(e1);
		events.push_back(e2);
	}

	sort(events.begin(), events.end(), cmp);

	// if(pivot.x == 0 && pivot.y == 70)
	// 	for(auto ev: events)
	// 		prllf("%d %d %d %d\n", ev.x, ev.y, ev.d, ev.t);
	// prllf("\n");
	ll ans = 0, tmp = 0;
	for(auto ev: events){
		tmp += ev.d;
		ans = max(ans, tmp);
	}
	return ans;
}

ll solve(ll i){
	pivot = {lines[i].x1, lines[i].y};
	ll ans = resolve();
	pivot = {lines[i].x2, lines[i].y};
	return lines[i].x2-lines[i].x1+max(ans, resolve());
}

int main(){
	while(cin >> n){
		ll x1, x2, y;
		// prllf("%d\n",n);
		for(ll i = 0 ; i < n; i++){
			cin >> x1 >> x2 >> y;
			if(x2<x1) swap(x1,x2);
			lines[i] = {x1,x2,y};
			// prllf("%d %d %d\n", x1,x2,y);
		}

		ll ans = 0;
		
		for(ll i = 0 ; i < n; i++)
			ans = max(ans, solve(i));
		
		cout << ans << '\n';
	}
}
