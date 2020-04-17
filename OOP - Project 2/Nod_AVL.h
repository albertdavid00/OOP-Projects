#pragma once
#include "Nod.h"

class Nod_AVL:public Nod{
protected:
	int echilibru;
public:
	Nod_AVL(int = 0, Nod* = NULL, Nod* = NULL, int = 0);
	Nod_AVL(const Nod_AVL&);
	~Nod_AVL();
	int getinfo();
	Nod* getst();
	Nod* getdr();
	Nod_AVL& operator=(const Nod_AVL&);
	friend istream& operator>>(istream&, Nod_AVL*&);
	friend ostream& operator<<(ostream&, const Nod_AVL*);
	friend class Arbore_AVL;
};