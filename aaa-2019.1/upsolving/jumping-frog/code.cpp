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
#define maxn 100010

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

char inp[maxn];
int ok[maxn];
int n;

string s;
int start(int i, int t){
	int v = n;
	for(int j = (i+t)%n; v--; j = (j+t)%n)
		if(s[j] == 'P')
			return 0;
	return 1;
}

int main(){
	while(getline(cin, s)){
		
		n = (int)s.size();
		// trace(s, n);
		for(int i =0; i <= n; i++)
			ok[i] = -1;

		int ans = 0;
		for(int i = 1; i < n; i++){
			int t = __gcd(i, n);
			if(ok[t] != -1)
				ok[i] = ok[t];
			else {
				ok[i] = 0;
				for(int j = 0; j < t; j++){
					// trace(s, i, t, ok[i]);
					ok[i] = start(j, t);
					if(ok[i]) break;
				}
			}
			ans += ok[i];
		}
		printf("%d\n", ans);
	}
 	return 0;
}

