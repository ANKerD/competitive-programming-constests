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
#define maxn 300010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}
char s[maxn];
int main(){
	int n, op=0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int i = 1; i < n-1; i++)
		if(s[i] != '?'){
			trace(":(");
			return 0;
		}

	int l=0, r=n-1;
	while(l < r){
		if(l == ')' || r == '(' || (n&1)){
			trace(":(");
			return 0;
		}
		s[l++] = '(';
		s[r--] = ')';
	}

	if(op != 0){
		trace(":(");
		return 0;
	} else {
		for(int i = 0; i < n; i++)
			cout << s[i];
		cout << '\n';
	}
 	return 0;
}

