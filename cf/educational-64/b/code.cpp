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

int n;
string s;

int ng(vector<char> &s, int i){
	if ( abs(s[i]-s[(i+1)%n]) == 1)
		return 1;
	return s[i] == 'a' && s[(i+1)%n] == 'z' || 
		   s[(i+1)%n] == 'a' && s[i] == 'z';
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s;
		vector<char> v;
		for (int j = 0; j < (int) s.size(); j++)
			v.pb(s[j]);
		for (int j = 0; j+1 < (int) s.size(); j++)
			if (ng(v,j))
				swap(v[j+1], v[j+2]);
		int err = 0;
		for (int j = 0; j+1 < (int) s.size(); j++)
			err += ng(v,j);
		// if(err){
		// 	cout << "No answer\n";
		// } else {
			trace(err);
			for (int j = 0; j < (int) s.size(); j++)
				cout << v[j];
			cout << '\n';
		// }
	}

 	return 0;
}

