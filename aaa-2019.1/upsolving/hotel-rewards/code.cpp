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
int a[maxn];
int main(){
	int n,k;
	while(scanf("%d %d", &n, &k) != EOF){
		int t = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			t += a[i];
		}
		k++;
		priority_queue<int, vi, greater<int> > q;
		for(int i = 0; i < n; i++){
			if(i && (i+1) % k == 0){
				// trace("adicionou", a[i]);
				q.push(a[i]);
			} else if(!q.empty() && q.top() < a[i]) {
				// trace("desenpilhou", q.top(), ", adicionou", a[i]);
				q.pop();
				q.push(a[i]);
			}
		}
		
		while(!q.empty()){
			t -= q.top();
			q.pop();
		}
		printf("%d\n", t);
	}
 	return 0;
}

