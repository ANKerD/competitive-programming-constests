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

int main(){
	int x, y;
	int ans = 0;
	cin >> x >> y;
	for (int i = 0; i < 1000; ++i)
		for (int j = 0; j < 1000; ++j)
			if (i*i+j == x && j*j+i==y)
				ans++;
	trace(ans);
 	return 0;
}

