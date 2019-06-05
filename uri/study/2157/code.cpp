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
	int n,l,r;
	cin >> n;
	while(n--){
		cin >> l >> r;
		for(int i = l; i <= r; i++)
			cout << i;
		for(int i = r; i >= l; i--){
			queue<int> s;
			int j = i;
			while(j){
				s.push(j%10);
				j /= 10;
			}
			while(!s.empty()){
				cout << s.front();
				s.pop();
			}
		}
		cout << '\n';
	}

 	return 0;
}

