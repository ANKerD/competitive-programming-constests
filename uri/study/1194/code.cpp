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
#define maxn 300

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int n;
string a,b;
int inner[maxn], pre[maxn];

int preIndex;
void solve(int l, int r){
	if(l < 0 || r >= n || l > r) return;
	
	int mid = inner[a[preIndex++]];
	char v = b[mid];
	
	solve(l, mid-1);
	solve(mid+1, r);
	cout << v;

}

int main(){
	int t;
	cin >> t;
	while(t--){
		preIndex = 0;
		cin >> n >> a >> b;
		for(int i = 0; i < n; i++){
			pre[  a[i]] = i;
			inner[b[i]] = i;
		}
		solve(0, n-1);
		cout << '\n';
	}
 	return 0;
}

