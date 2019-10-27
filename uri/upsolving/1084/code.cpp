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
	int n,m;
	string s;
	while(1){
		cin >> n >> m;
		if(!n & !m) break;
		cin >> s;
		int i = 0;
		stack<char> st;
		while(i < n && m > 0){
			while(!st.empty() && st.top() < s[i] && m > 0){
				st.pop();
				--m;
			}
			st.push(s[i]);
			++i;
		}
		// trace(n,m);
		while(i < n)
			st.push(s[i++]);
		while(m--) st.pop();
		vi a;
		
		while(!st.empty()){
			a.pb(st.top());
			st.pop();
		}


		reverse(a.begin(), a.end());
		for(int i = 0; i < a.size(); i++)
			cout << a[i]-48;
		cout << '\n';
	}

 	return 0;
}

