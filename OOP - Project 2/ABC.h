#pragma once
#include "Arbore.h"
#include "Nod.h"

class ABC:public Arbore{
	Nod* root;
	void Inorder(Nod*, ostream&) const;
public:
	ABC(int = 0, Nod* = NULL);
	ABC(const ABC&);
	~ABC();
	ABC& operator=(const ABC&);
	Nod* getroot();
	void setroot(Nod*);
	void Insert(int);
	void Delete(int);
	friend istream& operator>>(istream&, ABC&);
	friend ostream& operator<<(ostream&, const ABC&);
};