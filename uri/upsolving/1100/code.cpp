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

ii get(string &s){
	return {s[0]-'a', s[1]-'1'};
}

int main(){
	string s;
	while (getline(cin, s)) {
		ii src = {s[0]-'a', s[1]-'1'};
		ii dst = {s[3]-'a', s[4]-'1'};
		queue<pair<int, ii> > q;
		q.push({0, src});
		vi dx = {2, 2,1, 1,-1,-1,-2,-2};
		vi dy = {1,-1,2,-2,-2, 2, 1,-1};
		while(1) {
			int c = q.front().fi;
			int x = q.front().se.fi;
			int y = q.front().se.se;
			q.pop();
			if (x < 0 || x >= 8 || y < 0 || y >= 8) continue;
			if (x == dst.fi && y == dst.se) {
				printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],c);
				// q.clear();
				break;
			}
			for (int i = 0; i < dx.size(); ++i)
				q.push({c+1, {x+dx[i],y+dy[i]}});
		}
	}

 	return 0;
}