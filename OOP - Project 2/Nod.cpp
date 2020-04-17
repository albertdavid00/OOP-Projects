#include "Nod.h"

Nod::Nod(int i, Nod* prev, Nod* next) : info(i), st(prev), dr(next) {}

Nod::Nod(const Nod& p) {
	this->st = p.st;
	this->dr = p.dr;
	this->info = p.info;
}

Nod::~Nod() {
	st = dr = NULL;
}

int Nod::getinfo() {
	return info;
}
Nod* Nod::getdr() {
	return dr;
}
Nod* Nod::getst() {
	return st;
}

Nod& Nod::operator=(const Nod& p) {
	if (this != &p) {
		this->info = p.info;
		this->st = p.st;
		this->dr = p.dr;
	}
	return *this;
}

istream& operator>>(istream& in, Nod*& p) {
	int x;
	try {
		Nod* q = new Nod();
		cout << "Nod: ";
		in >> x;
		q->info = x;
		q->st = NULL;
		q->dr = NULL;
		p = q;
	}
	catch(bad_alloc& x){
		cout << "bad_alloc caught: " << x.what() << '\n';
		exit(1);
	}
	return in;
}

ostream& operator<<(ostream& out, const Nod* p) {
	out << p->info;
	return out;
}
