#pragma once
#include "Nod_AVL.h"
#include "Arbore.h"

class Arbore_AVL :public Arbore {
	Nod_AVL* root;
	void Inorder(Nod_AVL*, ostream&) const;
	int BalanceFactor(Nod*, Nod*);
	int MaxHeight(Nod*);
public:
	Arbore_AVL(int = 0, Nod_AVL* = NULL);
	Arbore_AVL(const Arbore_AVL&);
	~Arbore_AVL();
	Nod_AVL* getroot();
	void setroot(Nod_AVL*);
	void PrintEchilibru(Nod_AVL*) const;
	void Insert(int);
	Arbore_AVL& operator=(const Arbore_AVL&);
	friend istream& operator>>(istream&, Arbore_AVL&);
	friend ostream& operator<<(ostream&, const Arbore_AVL&);
};