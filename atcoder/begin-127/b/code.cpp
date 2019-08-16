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
	vi v;
	int a,b;
	cin >> a >> b;
	for (int i = b-a+1; i <= a+b-1; ++i)
		v.push_back(i);
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << " \n"[i+1==v.size()];
 	return 0;
}

