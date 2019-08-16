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
#define maxn 400010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];
int back[maxn];
map<int, int> go;

int main(){
	int n,I;
	cin >> n >> I;
	set<int> nums;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		nums.insert(a[i]);
	}
	int id = 0;
	for (auto u: nums) {
		go[u] = id;
		back[id] = u;
		++id;
	}
	for (int i = 0; i < n; ++i)
		a[i] = go[a[i]];
	sort(a,a+n);
	int cnt = 0;
	int i = 0, j = 0;
	while (i < n) {
		j=i+1;
		while (j < n && a[j]-a[i] < I)
			++j;
		int cur = j-i;
		trace(i, j, cur);
		cnt = max(cnt, cur);
		++i;
		while (i < j && a[j]-a[i] == I)
			++i;
	}
	trace(n-cnt);
	
 	return 0;
}

