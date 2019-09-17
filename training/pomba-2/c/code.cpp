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
#define INF 1e9 + 7

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

char s[MAX], t[MAX];
int dp[2][MAX];
int main(){
	scanf(" %s", s);
	scanf(" %s", t);

	int n = strlen(s);
	int ac = ceil((n*1.0)*0.99);
	int error = floor((n*1.0)-(n*0.99)) + 7;
	int b;
	for(int i = 1; i <= n; i++){
		b = i&1; 
		for(int j = max(1, (i-error)); j <= min(i+error, n); j++){
			if(i == 0 || j == 0) dp[b][j] = 0;
			else if(s[i-1] == t[j-1]) dp[b][j] = dp[1-b][j-1] + 1;
			else dp[b][j] = max(dp[1-b][j], dp[b][j-1]);
		}
	}
   
	if(dp[b][n] >= ac) printf("Long lost brothers D:\n");
	else printf("Not brothers :(\n");
 	return 0;
}

