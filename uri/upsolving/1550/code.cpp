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
#define maxn -879879

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int rev(int a) {
	int ans = 0;
	while (a) {
		ans = ans * 10 + a % 10;
		a /= 10;
	}
	return ans;
}

int main(){
	int t,a,b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		queue<ii> q;
		q.push({a,0});
		set<int> vis;
		while(1) {
			int n = q.front().fi;
			int c = q.front().se;
			q.pop();
			if (vis.count(n)) continue;
			vis.insert(n);
			if (n == b) {
				trace(c);
				break;
			}
			q.push({n+1,c+1});
			q.push({rev(n),c+1});
		}
	}
 	return 0;
}


