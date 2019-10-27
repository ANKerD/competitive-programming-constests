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
	while(cin >> n){
		int y,x;
		stack<int> s;
		queue<int> q;
		priority_queue<int> p;
		int s1=1,s2=1,s3=1;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			if(x == 1){
				s.push(y);
				q.push(y);
				p.push(y);
			} else {
				if(s.top() != y) s1 = 0;
				if(q.front() != y) s2 = 0;
				if(p.top() != y) s3 = 0;
				s.pop();
				q.pop();
				p.pop();
			}
		}

		if(s1+s2+s3 == 1){
			if(s1) cout << "stack\n";
			if(s2) cout << "queue\n";
			if(s3) cout << "priority queue\n";
		} else if (s1+s2+s3 == 0)
			cout << "impossible\n";
		else
			cout << "not sure\n";
		
	}
 	return 0;
}

