#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define ld long double
#define vii vector<ii>
#define vll vector<ll>
#define maxn 511111

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int sz[maxn];

int find_set(int x, vector<int> &parents){
    if(x == parents[x]){
        return x;
    }
    parents[x] = find_set(parents[x], parents);
    return parents[x];
}

void union_find(int x, int y, vector<int> &parents){
    x = find_set(x, parents);
    y = find_set(y, parents);
    if(x != y){
        parents[y] = x;
		sz[x] += sz[y];
		// sz[y] = 0;
    }
}

vector<int> instance_parents(int m){
    vector<int> parents;
    for(int i = 0; i < maxn; i++){
		sz[i] = 1;
        parents.push_back(i);
    }
    return parents;
}

int main(){
	int n, m;
	cin >> n >> m;
	vi p = instance_parents(n);

	for(int i = 0; i < m; i++){
		int j;
		cin >> j;
		// trace(i, j);
		if(j){
			int a,b;
			cin >> a;
			for(int k = 1; k < j; k++){
				cin >> b;
				union_find(a,b,p);
			}
		}
	}

	for(int i = 1; i <= n; i++)
		cout << sz[find_set(i, p)] << " \n"[i==n];

 	return 0;
}

