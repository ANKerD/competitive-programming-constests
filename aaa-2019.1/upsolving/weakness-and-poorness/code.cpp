#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
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

int n;

void pr(ld a[]){
	for(int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}

ld a[maxn];

ld kadane(){
	ld ans = 0;
	ld ac = 0;
	for(int i = 0; i < n; i++){
		ac += a[i];
		ac = max(0.0l, ac);
		ans = max(ans, ac);
	}
	return ans;
}

ld weakness(ld x){
	for(int i = 0; i < n; i++)
		a[i] -= x;
	ld ans = kadane();
	
	for(int i = 0; i < n; i++)
		a[i] *= -1;
	ans = max(ans, kadane());

	for(int i = 0; i < n; i++){
		a[i] *= -1;
		a[i] += x;
	}

	return ans;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	int tr = 300;
	ld l = -1e4,r = 1e4;
	
	ld ans = 1e10;
	while(tr--){
		ld m1 = (2.0*l+r)/3.0;
		ld m2 = (2.0*r+l)/3.0;

		ld w1 = weakness(m1);
		ld w2 = weakness(m2);

		ans = min(ans, max(w1,w2));

		if(w1 > w2) l = m1;
		else r = m2;
	}

	printf("%.32Lf\n", ans);
	
 	return 0;
}

