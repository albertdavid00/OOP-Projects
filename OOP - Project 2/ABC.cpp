#include "ABC.h"

ABC::ABC(int n, Nod* p):Arbore(n),root(p){}

ABC::ABC(const ABC& A):Arbore(A){
	this->root = A.root;
}

ABC::~ABC() {}

ABC& ABC::operator=(const ABC& A){
	if (this != &A) {
		Arbore::operator=(A);
		this->root = A.root;
	}
	return *this;
}
Nod* ABC::getroot() {
	return root;
}

void ABC::setroot(Nod* x) {
	root = x;
}

void ABC::Insert(int key) {			// metoda de inserare a unui nod in arbore
	if (nr_noduri == 0) {
		root = new Nod(key);
		nr_noduri = 1;
		return;
	}		
	Nod* p = new Nod(key);
	Nod* q = root;
	Nod* trail = NULL;
	while (q != NULL) {
		trail = q;
		if (key < q->info)
			q = q->st;
		else if (key > q->info)
			q = q->dr;
		else {
			try {
				if (key == q->info)
					throw key;
			}
			catch (int x) {
				cout << "Numarul " << x << " a mai fost introdus.\nNumerele trebuie sa fie distincte!";
				exit(1);
			}
		}
	}
	if (trail != NULL) {
		if (key < trail->info)
			trail->st = p;
		else
			trail->dr = p;
	}
	nr_noduri++;
}

void ABC::Delete(int key) {
	if (nr_noduri == 0)
		return;
	Nod* p = root;
	Nod* q = p;
	while (p->info != key) {
		q = p;
		if (key < p->info)
			p = p->st;
		else
			p = p->dr;
		if (p == NULL) {
			cout << "Nodul "<<key<< " nu se afla in arbore" << '\n';
			return;
		}
	}
	
	if (p->st == NULL && p->dr == NULL) {	//nodul nu are fii
		if (p == root) {
			root = NULL;
			nr_noduri--;
			return;
		}
		if (q != NULL) {
			if (q->st == p)
				q->st = NULL;
			else
				q->dr = NULL;
		}
		delete p;
		nr_noduri--;
		return;
	}
	else if (p->st == NULL) {		//are doar fiu drept	
		if (q->st != NULL && q->st->info == key) {
			q->st = p->dr;
		}
		else if (q->dr != NULL && q->dr->info == key) {
			q->dr = p->dr;
		}
		else {
			root = root->dr;	// p = q = root
		}
		delete p;
		nr_noduri--;
		return;
	}
	else if (p->dr == NULL) {		// are doar fiu stang
		if (q->st != NULL && q->st->info == key) {
			q->st = p->st;
		}
		else if (q->dr != NULL && q->dr->info == key) {
			q->dr = p->st;
		}
		else {
			root = root->st;		// p = q = root
		}
		delete p;
		nr_noduri--;
		return;
	}
	else {					//daca nodul are 2 fii
		bool ok = 0;
		Nod* trail, * replace;
		trail = p;
		replace = p->st;
		while (replace->dr != NULL) {
			trail = replace;
			replace = replace->dr;
			ok = 1;			//intra cel putin o data in while
		}
		if (!ok) {		// trail->st->dr == NULL
			if (root == p) {
				root->info = replace->info;
				root->st = replace->st;
				delete replace;
				nr_noduri--;
				return;
			}
			else {
				if (q->dr && q->dr->info == p->info)
					q->dr = replace;
				else if(q->st && q->st->info == p->info)
					q->st = replace;
				replace->dr = p->dr;
				delete p;
				nr_noduri--;
				return;
			}
		}
		if (replace->st != NULL) {
			if (ok)
				trail->dr = replace->st;
			else
				trail->st = replace->st;
		}	
		p->info = replace->info;
		delete replace;
		trail->dr = NULL;
		nr_noduri--;
		return;
	}
}

void ABC::Inorder(Nod* root, ostream& os) const{	// metoda de parcurgere si afisare in ordine a arborelui 
	if (root == NULL)
		return;
	else {
		Inorder(root->getst(), os);
		os << root->getinfo() << " ";
		Inorder(root->getdr(), os);
	}
}

ostream& operator<<(ostream& out, const ABC& A) {
	Nod* p = A.root;
	A.Inorder(p, out);
	return out;
}

istream& operator>>(istream& in, ABC& A) {
	int key, n;
	cout << "Nr elemente ABC: ";
	in >> n;
	cout << "Elemente ABC: ";
	for (int i = 0; i < n; i++) {
		in >> key;
		A.Insert(key);
	}
	return in;
}

