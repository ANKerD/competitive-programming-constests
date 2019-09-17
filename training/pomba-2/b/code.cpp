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
#define MAX 100007


template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int k[MAX];

int kmp(string s){
	int i = 0, j = -1;

	k[0] = -1;
	while(i < s.size()){
		while(j >= 0 && s[i] != s[j]) j = k[j];
		i++; j++;
		k[i] = j;
	}

	return k[s.size()];
}
int main(){
	string s; cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	int start = kmp(t + "$" + s);
	cout << s << t.substr(start, s.size()-start) << endl;
 	return 0;
}

