#include <bits/stdc++.h>
using namespace std;

struct item {
	int key, prior;
	item *l, *r;
	item(){}
	item(int key, int prior): key(key), prior(prior), l(NULL), r(NULL) {}
};

typedef item* pitem;

void split(pitem t, int key, pitem &l, pitem &r){
	if(!t)
		l = r = NULL;
	else if(key < t->key)
		split(t->l, key, l, t->l), r = t;
	else
		split(t->r, key, t->r, r), l = t;
}

void merge(pitem &t, pitem l, pitem r){
	if(!l || !r)
		t = l ? l : r;
	else if(l->prior >  r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
}

void insert(pitem &t, pitem &it){
	if(!t)
		t = it;
	else if(it->prior > t->prior)
		split(t, it->key, it->l, it->r), t = it;
	else
		insert(it->key < t->key ? t->l : t->r, it);
}

int getPrior(){
	return (rand() << 16)|rand();
}

void insert(pitem &t, int key){
	int prior = getPrior();
	item newItem = item(key, getPrior());
	printf("%d \n", newItem.key);
	// pitem l, r;
	// split(t, key, l, r);
	// merge(l, l, &newItem);
	// merge(t, l, r);
}

int main(){
	srand(time(NULL));

	int n,num;
	char op;
	scanf("%d", &n);
	pitem treap;
	treap->key = 90;
	insert(treap, 80);
	printf("%d %d\n", treap->key, treap->l->key);
	// insert(treap, 100);
	// printf("%d %d %d\n", treap->key, treap->l->key, treap->r->key);
	// for(int i = 0; i < n; i++){
	// 	scanf("%c %d", &op, &num);
	// 	if(op == 'I') insert(treap, num);
	// }

 	return 0;
}

