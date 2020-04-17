#include "Arbore.h"
#include "Nod.h"

Arbore::Arbore(int x):nr_noduri(x){}		// constructor

Arbore::Arbore(const Arbore& A) {			// copy-constructor
	this->nr_noduri = A.nr_noduri;
}

Arbore::~Arbore(){							// destructor
	nr_noduri = 0;
}

Arbore& Arbore::operator=(const Arbore& A){		// operator= overloading	
	if (this != &A) {
		this->nr_noduri = A.nr_noduri;
	}
	return *this;
}
