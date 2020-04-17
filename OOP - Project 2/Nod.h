#pragma once
#include <iostream>
#include <new>
using namespace std;

class Nod {
protected:
	int info;
	Nod* st, * dr;
public:
	Nod(int = 0, Nod* = NULL, Nod* = NULL);
	Nod(const Nod&);
	virtual ~Nod();
	int getinfo();
	Nod* getdr();
	Nod* getst();
	Nod& operator=(const Nod&);
	friend istream& operator>>(istream&, Nod*&);
	friend ostream& operator<<(ostream&, const Nod*);
	friend class Arbore;
	friend class ABC;
	friend class Arbore_AVL;
};