#include "Nod_AVL.h"

Nod_AVL::Nod_AVL(int inf, Nod* p, Nod* q, int balance):Nod(inf,p,q),echilibru(balance){}

Nod_AVL::Nod_AVL(const Nod_AVL& A) : Nod(A) {
	this->echilibru = A.echilibru;
}

Nod_AVL::~Nod_AVL() {
	echilibru = 0;
}

int Nod_AVL::getinfo()
{
	return info;
}

Nod* Nod_AVL::getst()
{
	return st;
}

Nod* Nod_AVL::getdr()
{
	return dr;
}

Nod_AVL& Nod_AVL:: operator=(const Nod_AVL& A) {
	if (this != &A) {
		Nod::operator=(A);
		this->echilibru = A.echilibru;
	}
	return *this;
}

istream& operator>>(istream& in, Nod_AVL*& p) {
	int x, y;
	Nod_AVL* q = new Nod_AVL();
	cout << "Info Nod-AVL: ";
	in >> x;
	q->info = x;
	cout << "Factor de echilibru: ";
	in >> y;
	q->echilibru = y;
	p = q;
	return in;
}

ostream& operator<<(ostream& out, const Nod_AVL* p) {
	cout << "Info nod_avl: ";
	if (p) {
		out << p->info;
		cout << " Factor de echilibru: ";
		out << p->echilibru;
	}
	return out;
}