#include "ABC.h"
#include "Nod_AVL.h"
#include "Arbore_AVL.h"

int main()
{
	Arbore_AVL B;
	int n, m;
	cout << "Nr arbori AVL: ";
	cin >> n;
	Arbore_AVL* v;
	try {
		v = new Arbore_AVL[n];
	}
	catch (bad_alloc bd) {
		cout << "Allocation Failure\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++) {
		cout << v[i];
		v[i].PrintEchilibru(v[i].getroot());
	}
	delete[]v;

	cout << "\nNr arbori ABC: ";
	cin >> m;
	ABC* w;
	try {
		w = new ABC[m];
	}
	catch(bad_alloc bd){
		cout << "Allocation Failure\n";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < m; i++)
		cin >> w[i];
	for (int i = 0; i < m; i++)
		cout << w[i];
	delete[]w;
	return 0;
}