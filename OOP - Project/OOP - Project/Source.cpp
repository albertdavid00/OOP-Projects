#include <iostream>
using namespace std;

class Nod {
	int info;
	Nod* prev;
	Nod* next;
public:
	Nod() {
		info = 0;
		prev = next = NULL;;
	}
	Nod(int i) {
		info = i;
		prev = next = NULL;
	}
	Nod(int i, Nod* p, Nod* q) {
		info = i;
		prev = p;
		next = q;
	}
	~Nod() {
		prev = NULL;
		next = NULL;
	}
	int getinfo() {
		return info;
	}
	Nod* getnext() {
		return next;
	}
	Nod* getprev() {
		return prev;
	}
	friend class Lista_dublu_inlantuita;
};
class Lista_dublu_inlantuita{
	Nod* prim;
	Nod* ultim;
	int length;
public:
	Lista_dublu_inlantuita() {
		prim = NULL;
		ultim = NULL;
		length = 0;
	}
	Lista_dublu_inlantuita(Nod* p, int x) {
		prim->info = ultim->info = x;
		prim = ultim = p;
		length = 1;
	}
	Lista_dublu_inlantuita(Nod* p, Nod* q, int len) {
		prim = p;
		ultim = q;
		length = len;
	}
	int getlen() {
		return length;
	}
	void Add(int x, int poz) {
		if (length == 0){
			prim = ultim = new Nod(x);
			length = 1;
			return;
		}
		Nod* nou = new Nod(x);
		if (poz == 0){
			nou->next = prim;
			prim->prev = nou;
			prim = nou;
		}
		else if (poz < length){
			Nod* p = prim;
			while (poz > 0){
				p = p->next;
				poz--;
			}
			nou->next = p->next;
			if (p->next) {
				nou->prev = p->next->prev;
				p->next->prev = nou;
			}
			else {
				nou->prev = p;
			}
			p->next = nou;
		}
		else{
			ultim->next = nou;
			nou->prev = ultim;
			nou->next = NULL;
			ultim = nou;
		}
		length++;
	}
	void Delete(int poz) {
		if (length == 0) {
			return;
		}
		else if (poz == 1) {
			Nod* p = new Nod;
			p = prim;
			if (p->next) {
				prim = p->next;
				prim->prev = NULL;
				delete p;
			}
			else {
				delete prim;
				prim = ultim = NULL;
			}
			length--;
		}
		else if (poz < length) {
			Nod* p = new Nod;
			Nod* s = new Nod;
			p = prim;
			while (poz>2) {
				p = p->next;
				poz--;
			}
			s = p->next;
			if(s->next)
				p->next->next->prev = p;
			p->next = p->next->next;
			delete s;
			length--;
		}
		else {
			Nod* p = new Nod; 
			p = ultim;
			ultim = ultim->prev;
			if(ultim)
				ultim->next = NULL;
			delete p;
			length--;
		}
	}
	Lista_dublu_inlantuita operator+(Lista_dublu_inlantuita& Lista2) {
		Lista_dublu_inlantuita Lista3;
		Nod* p = this->prim;
		int k = 0;
		while (p) {
			Lista3.Add(p->info, k);
			k++;
			p = p->next;
		}
		p = Lista2.prim;
		while (p) {
			Lista3.Add(p->info, k);
			k++;
			p = p->next;
		}
		return Lista3;
	}
	friend class Nod;
	friend ostream& operator << (ostream& out, const Lista_dublu_inlantuita& Lista);
	friend istream& operator >> (istream& in, Lista_dublu_inlantuita& Lista);
};
ostream& operator << (ostream& out, const Lista_dublu_inlantuita& Lista){
	Nod* p = Lista.prim;
	cout << "\n";
	if (!p)
		cout << "Lista este vida. ";
	else {
		cout << "Lista in ordine: ";
		while (p) {
			out << p->getinfo() << " ";
			p = p->getnext();
		}
		cout << "\n"<<"Lista in ordine inversa: ";
		p = Lista.ultim;
		while (p) {
			out << p->getinfo() << " ";
			p = p->getprev();
		}
		cout << '\n';
	}
	return out;
}
istream& operator >> (istream& in, Lista_dublu_inlantuita& Lista){
	int x, n, k=0;
	cout << "Nr elemente: ";
	in >> n;
	cout << "Elementele listei: ";
	for (int i = 1; i <= n; ++i) {
		in >> x;
		Lista.Add(x, ++k);
	}
	return in;
}
int main()
{
	int n,i;
	cin >> n;
	Lista_dublu_inlantuita x, * array = new Lista_dublu_inlantuita[n];
	for (i = 0; i < n; i++) {
		cin >> array[i];
		x = x + array[i];
	}
	for (i = 0; i < n; i++) {
		cout << array[i];
	}
	cout<<'\n'<<"Lista obtinuta dupa concatenarea tuturor listelor: "<< x;

	x.Delete(x.getlen() % 2 ? x.getlen() / 2 + 1 : x.getlen() / 2);
	cout << "\n" << "Lista obtinuta dupa eliminarea elementului din mijloc: " << x;
	delete[] array;
	return 0;
}