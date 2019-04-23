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
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int st[8*maxn+1];
// void(up)
bool acum[8*maxn];
int left(int x){return 2*x;}
int right(int x){return 2*x+1;}

void build(int id, int l, int r){
	if(l == r){
		st[id] = 1;
		acum[id] = 0;
	} else {
		int mid = (l+r)/2;
		build(left(id), l, mid);
		build(right(id), mid+1, r);
	}
}

void propagate(int id, int l, int r){
	if(acum[id]){
		if(l == r){
			st[id] = -st[id];
		} else {
			acum[left(id)] = acum[id]+acum[left(id)];
			acum[right(id)] = acum[id]^acum[right(id)];
		}
		acum[id] = 0;
	}
}

int query(int id, int l, int r, int index){
	propagate(id, l, r);
	if(l == r)
		return st[id];
	
	int mid = (l+r)/2;
	if(index <= mid)
		return query(left(id), l, mid, index);
	return query(right(id), mid+1, r, index);
}

void update(int id, int l, int r, int bg, int nd){
	propagate(id, l, r);
	if(r < bg || l > nd) return;
	if(l >= bg && r <= nd){
		acum[id] = !acum[id];
		return;
	}
	int mid = (l+r)/2;
	update(left(id), l, mid, bg, nd);
	update(right(id), mid+1, r, bg, nd);
}

int a[maxn];

int main(){
	int n,q,x,y,num;
	char op;
	build(1,0,2*maxn);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];

	for(int i = 0; i < q; i++){
		cin >> op >> num;
		num += maxn;
		if(op == '<')	
			update(1, 0, 2*maxn, 0, num-1);
		else
			update(1, 0, 2*maxn, num+1, 2*maxn);
	}
	
	for(int i = 0; i < n; i++){
		int x = query(1,1,2*maxn, maxn+a[i])*a[i];
		cout << x << " \n"[i+1==n];
	}
	
 	return 0;
}

