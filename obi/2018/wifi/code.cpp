#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define treeparams 1, 1, 2*n, y1, y2

struct evento {
	int y1, y2, x, t, id;
};

int entrada = 1;
int saida = entrada+1; //so pra garantir que vão ser diferentes

int tree[4*maxn];
int acum[4*maxn];
int entrou[maxn];

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

inline int left(int x){ return x<<1;}
inline int right(int x){ return (x<<1)|1;}

void inline propagate(int id, int l, int r){
	if(!acum[id]) return;
	
	tree[id] += (r-l+1) * acum[id];
	
	if(l != r) {
		acum[left(id)] += acum[id],
		acum[right(id)] += acum[id];
	}
	
	acum[id] = 0;
}

void update(int id, int l, int r, int st, int nd){
	propagate(id, l, r);
	if (r < st || l > nd)
		return;
	if (l >= st && r <= nd){
		tree[id] += r-l+1;
		if(l != r) {
			++acum[left(id)],
			++acum[right(id)];
		}
		return;
	}
	int mid = (l+r)>>1;
	update(left(id), l, mid, st, nd);
	update(right(id), mid+1, r, st, nd);
	tree[id] = tree[left(id)]+tree[right(id)];
}

int query(int id, int l, int r, int st, int nd){
	if (r < st || l > nd || l > r)
		return 0;
	propagate(id, l, r);
	if (l >= st && r <= nd)
		return tree[id];
	int mid = (l+r)>>1;
	return 
		query(left(id), l, mid, st, nd) +
		query(right(id), mid+1, r, st, nd);
}
bool cmp(evento a, evento b){
	return a.x < b.x;
}

int32_t main(){
	memset(tree, 0, sizeof tree);
	memset(acum, 0, sizeof acum);
	int n,x1,x2,y1,y2;
	cin >> n;
	vector<evento> ev;
	set<int> sy;
	for(int i = 0; i < n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		ev.push_back({y2, y1, x1, entrada, i});
		ev.push_back({y2, y1, x2, saida, i});
		// trace(y2, y1, x1, x2);
		sy.insert(y1); sy.insert(y2);
	}

	int index = 1;
	map<int, int> go;
	for (auto it = sy.begin(); it != sy.end(); ++it)
		go[*it] = index++;

	sort(ev.begin(), ev.end(), cmp);

	int roteadores = 0;
	for(int i = 0; i < 2*n; i++){
		evento e = ev[i];
		int y1 = go[e.y1];
		int y2 = go[e.y2];
		int pos = e.id;
		if (e.t == entrada){
			update(treeparams);
			entrou[pos] = query(treeparams);
		} else {
			if (query(treeparams) == entrou[pos]){
				++roteadores;
			}
		}
	}

	cout << roteadores << '\n';

 	return 0;
}
