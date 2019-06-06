#include <bits/stdc++.h>
using namespace std;
#define vi std::vector<int>
// #define maxn 1010
#define maxn 100010
#define maxsz 47
#define int long long

template<typename T>
void trace(T a){ cout << a << '\n';}
template<typename T, typename... Args>
void trace(T a, Args ...args){ cout << a << ' '; trace(args...);}

int arr[maxn];
vi seg[4*maxn];

vi combine(vi l, vi r) {
	vi ret(2*maxsz);
	merge(l.begin(), l.end(), r.begin(), r.end(), ret.begin());
	while (ret.size() > maxsz)
		ret.pop_back();
	return ret;
}

vi combine(int l, int r) {
	return combine(seg[l], seg[r]);
}

void build(int id, int l, int r){
    if(l == r) {
		seg[id].clear();
		seg[id].push_back(arr[l]);
	} else {
        int mid = (l+r)/2;
        build(2*id, l, mid);
        build(2*id+1, mid+1, r);

        seg[id] = combine(id*2, 2*id+1);
    }
}

void update(int id, int l, int r, int val, int x){
	// trace( id,  l,  r,  x,  val);
    if(l == r) {
		seg[id].clear();
		seg[id].push_back(val);
	} else {
        int mid = (l+r)/2;
        if(mid >= x) update(2*id, l, mid, val, x);
        else update(2*id+1, mid+1, r, val, x);

        seg[id] = combine(id*2, 2*id+1);
    }
}

vi query(int id, int l, int r, int x, int y){
	vi nil(maxsz);
    if(l > y || r < x) return nil;
    else if( x <= l && r <= y) return seg[id];
    else{
        int mid = (l+r)/2;
        return combine(query(2*id, l, mid, x, y), query(2*id+1, mid+1, r, x, y));
    }
}

int32_t main(){
	int n,q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i] = -arr[i];
	}
	build(1, 0, n-1);
	int op,x,y;
	for (int i = 0; i < q; ++i) {
		cin >> op >> x >> y;

		if (op == 1) {
			update(1, 0, n-1, -y, x-1);
		} else {
			vi rng = query(1, 0, n-1, x-1, y-1);
			int ans = 0;
			for (int j = 2; j < (int) rng.size(); ++j)
				if (rng[j-2] > rng[j-1] + rng[j] && rng[j-2] != 0 && rng[j-1] != 0 && rng[j] != 0) {
					ans = rng[j-2] + rng[j-1] + rng[j];
					break;
				}
			trace(-ans);
		}
	}

 	return 0;
}

