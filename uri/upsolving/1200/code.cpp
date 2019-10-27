#include <bits/stdc++.h>
using namespace std;
#define GHOST "'$*@%!*'"
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

struct bst {
	string v;
	bst *l, *r;
	bst(){l = r = NULL; v = GHOST;}
};

void inline extend(bst *node) {
	if (node->v == GHOST) {
		node->l = new bst();
		node->r = new bst();
	}
}

void insert(bst *node, string v) {
	extend(node);
	if (node->v == GHOST) {
		node->v = v;
		return;
	}
	if (v < node->v) 
		insert(node->l, v);
	else
		insert(node->r, v);
}

bool contains(bst *node, string v) {
	extend(node);
	if (node->v == GHOST) {
		return false;
	}
	if (node->v == v) {
		return true;
	}
	if (v < node->v) 
		return contains(node->l, v);
	else
		return contains(node->r, v);
}

vector<string> path;

void infix(bst *node) {
	extend(node);
	if (node->v == GHOST)
		return;
	infix(node->l);
	path.push_back(node->v);
	infix(node->r);
}

void posfix(bst *node) {
	extend(node);
	if (node->v == GHOST)
		return;
	posfix(node->l);
	posfix(node->r);
	path.push_back(node->v);
}

void prefix(bst *node) {
	extend(node);
	if (node->v == GHOST)
		return;
	path.push_back(node->v);
	prefix(node->l);
	prefix(node->r);
}

void prPath() {
	for (int i = 0; i < path.size(); ++i)
		cout << path[i] << " \n"[i+1 == path.size()];
}

int main(){
	string s;
	bst *root = new bst();
	while (cin >> s) {
		path.clear();
		if (s == "INFIXA") {
			infix(root);
			prPath();
		} 
		else if (s == "POSFIXA") {
			posfix(root);
			prPath();
		}
		else if (s == "PREFIXA") {
			prefix(root);
			prPath();
		}
		else if (s == "I") {
			cin >> s;
			insert(root, s);
		}
		else if (s == "P") {
			cin >> s;
			if (contains(root, s))
				printf("%s existe\n", s.c_str());
			else
				printf("%s nao existe\n", s.c_str());
		}
	}
 	return 0;
}


