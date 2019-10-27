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
#define pr(v) for (int i=0; i <v.size();i++) cout << v[i] << " \n"[i+1==v.size()]

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n;
        cin >> n;
        while(n--){
            string pt;
            cin >> pt;
            
            int i = 0, j=0;
            while (j < pt.size() && i < s.size())
                if(s[i++] == pt[j]){
                    // trace(i-1, j);
                    j++;
                }
            
            bool ok = j == pt.size();
            
            if(ok)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
 	return 0;
}

