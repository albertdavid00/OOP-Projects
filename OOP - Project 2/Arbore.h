#pragma once
#include <iostream>
#include "Nod_AVL.h"
using namespace std;

class Arbore{
protected:
	int nr_noduri;
public:
	Arbore(int = 0);
	Arbore(const Arbore&);
	virtual void Insert(int) = 0;
	virtual ~Arbore() = 0;
	Arbore& operator=(const Arbore&);
};