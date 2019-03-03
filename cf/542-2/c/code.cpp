#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define maxn 51
#define mod 1000000007
#define md(x) (x) % mod;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

template<typename T>
void trace(T a){
	cout << a << '\n';
}

template<typename T, typename... Args>
void trace(T a, Args... args){
	cout << a << ' ';
	trace(args...);
}
int n;
bool m[maxn][maxn];

vii pt[maxn*maxn];

int get(int i,int j){return i*maxn+j;}
int p[maxn*maxn];

int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};

int find(int id){
	// trace(id);
	if(p[id] == id) return id;
	return p[id] = find(p[id]);
}

bool wet(int idx){
	// return 0;;
	return m[idx/maxn][idx%maxn];
}

void join(int i, int j, int k,int l){
	int id1 = get(i,j);
	int id2 = get(k,l);
	
	id1 = find(id1);
	id2 = find(id2);
	
	if(id1 == id2 || wet(id1) || wet(id2)) return;
	
	auto *v1 = &pt[id1];
	auto *v2 = &pt[id2];

	
	if((int) v1->size() < (int) v2->size()){
		swap(v1,v2);
		swap(id1,id2);
	}

	for(auto z: (*v2)) v1->pb(z);
	p[id2] = id1;
}

void go(int i, int j){
	if(m[i][j]) return;
	
	for(int q = 0; q < 4; q++){
		int ii = i+y[q];
		int jj = j+x[q];
		
		if(ii < 1 || jj < 1 || ii > n || jj > n || m[ii][jj]) 
			continue;
		
		join(i,j,ii,jj);
	}
}

int main(){
	cin >> n;
	
	int a,b;
	cin >> a >> b;
	int src = get(a,b);
	cin >> a >> b;
	int dest = get(a,b);
	int ans = INF;
	
	for(int i = 1; i <= n; i++){
		string h;
		cin >> h;
		for(int j = 1; j <= n; j++){
			m[i][j] = h[j-1]=='1';
			p[get(i,j)] = get(i,j);
			pt[get(i,j)].pb(mp(i,j));
			// cout << m[i][j];
		}
		// cout << '\n';
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			go(i,j);
	
	src = find(src);
	dest = find(dest);
	for(auto ss: pt[src]){
		// trace(ss.fi,ss.se);
	}
	for(auto ss: pt[src])
		for(auto dd: pt[dest]){
			int dx = ss.fi-dd.fi;
			int dy = ss.se-dd.se;
			ans = min(ans,dx*dx+dy*dy);
		}
	trace(ans);
 	return 0;
}
