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
	int n;
	while(1){
		cin >> n;
		char x;
		if (!n) break;
		stack<char> c;
		queue<char> a,b;
		for(char i = 0; i < n; i++){
			cin >> x;
			a.push(x);
		}
		for(int i = 0; i < n; i++){
			cin >> x;
			b.push(x);
		}

		while(!a.empty() && !b.empty()){
			// cout << 'I' << a.front()  << ' ';
			cout << 'I';
			c.push(a.front());
			a.pop();
			while(!c.empty() && b.front() == c.top()){
				cout << 'R';
				b.pop();
				c.pop();
			}
		}
		if(!a.empty() ^ !b.empty())
			cout << " Impossible";
		cout << '\n';
		// break;
	}

 	return 0;
}

