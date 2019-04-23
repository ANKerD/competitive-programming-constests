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
#define maxn 1000010
#define INF 1000000000

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

struct line{
	int x1,x2,y1,y2;
	line(){};
	line(int _x1, int _x2, int _x3, int _x4){
		x1 = _x1;
		x2 = _x2;
		y1 = _x3;
		y2 = _x4;
	};
};

line lines[maxn];

bool cmp(line a, line b){
	if(a.x1 != a.x2)
		return a.x1 < a.x2;
	return a.y1 > a.y2;
}

int inline left(int x){return x<<1;}
int inline right(int x){return (x<<1)|1;}

int st[4*maxn];

void build(int id, int l, int r){
	if(l == r){
		st[id] = l;
	} else {
		int mid = (l+r)/2;
		build(left(id), l, mid);
		build(right(id), mid+1, r);
	}
}

int main(){
	int n,c,x1,x2,x3,x4;
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> x1 >> x2 >> x3 >> x4;
		lines[i] = line(x1,x2,x3,x4);
	}
	
	sort(lines, lines+n, cmp);

 	return 0;
}

