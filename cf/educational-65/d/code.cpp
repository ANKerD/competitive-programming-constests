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
#define maxn 211111

int ans[maxn];

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	// int last = 1;
	stack<int> op;
	op.push(1);
	for(int i = 0; i < n; i++){
		if (s[i] == ')'){
			ans[i] = op.top();
			// trace(i,op.top());
			op.pop();
			continue;
		}
		ans[i] = !op.top();
		op.push(!op.top());
		// last = 1-last;
	}

	for(int i = 0; i < n; i++)
		cout << ans[i];
	cout << '\n';

 	return 0;
}

