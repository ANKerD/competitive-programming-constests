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
#define maxn 1000100

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn], n;

int sv(){
	int ans = 0;
	int dt = 0;
	for (int i = 1; i < n; ++i)
		ans += abs(a[i]-a[i-1]);

	priority_queue<ii> pq;
	for (int i = 1; i+1 < n; ++i)
		pq.push(mp(abs(a[i+1]+a[i])+abs(a[i-1]+a[i]), i));

	ii top = pq.top();
	pq.pop();
	if(top.se == pq.top().se)
		pq.pop();

	return ans - top.fi-pq.top().fi;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int x = sv();
	for (int i = 0; i < n; ++i)
		a[i] = -a[i];
	cout <<  min(x,sv()) << '\n';

 	return 0;
}

