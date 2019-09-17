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

bool check(char a){
	return a >= '0' && a <= '9';
}
int main(){
	string s; cin >> s;
	int n = s.size();
	int i = 0;
	string ans = "";
	while(i < n && check(s[i])) ans += s[i++];
	if(i == 0) { cout << -1 << endl; return 0; }

	cout << ans << endl;
 	return 0;
}

