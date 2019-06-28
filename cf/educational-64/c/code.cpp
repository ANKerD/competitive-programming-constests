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
#define maxn 200010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int a[maxn];
int main(){
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	int i = 0, j = 0, ans = 0;
	j = n/2;
	while(j < n && i < n/2){
		while(j < n && a[j]-a[i] < k)
			j++;
		if(j < n && a[j]-a[i] >= k) ans++;
		i++;
	}
	int tmp = 0;
	j = n/2+1;
	while(j < n && i <= n/2){
		while(j < n && a[j]-a[i] < k)
			j++;
		if(j < n && a[j]-a[i] >= k) tmp++;
		i++;
	}
	cout << max(ans,tmp) << '\n';
 	return 0;
}

