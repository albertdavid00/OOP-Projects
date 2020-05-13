#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

/*
	Examen-> Partial
		  -> Final
		  -> Quiz
	Catalog_Individual<T>
	Catalog_Individual<Quiz>
*/


// ------------------------------------------------------- EXAMEN -------------------------------------------------

class Examen {
protected:
	static int contor_examen;
	string materie;
	int nota_scris;
	int id_examen;
public:
	Examen();
	Examen(string, int);
	Examen(const Examen&);
	virtual ~Examen();
	Examen& operator=(const Examen&);
	virtual	void citire(istream&);
	virtual void afisare(ostream&) const;
	friend istream& operator>>(istream&, Examen&);
	friend ostream& operator<<(ostream&, const Examen&);
};
int Examen::contor_examen = 0;
Examen::Examen() {
	contor_examen++;
	materie = "";
	nota_scris = 0;
	id_examen = contor_examen;
}
Examen::Examen(string m, int nota) {
	contor_examen++;
	materie = m;
	nota_scris = nota;
	id_examen = contor_examen;
}
Examen::Examen(const Examen& E) {
	contor_examen++;
	materie = E.materie;
	nota_scris = E.nota_scris;
	id_examen = contor_examen;
}
Examen::~Examen() {
	materie = "";
	nota_scris = 0;
}
Examen& Examen::operator=(const Examen& E) {
	if (this != &E) {
		this->materie = E.materie;
		this->nota_scris = E.nota_scris;
		this->id_examen = E.id_examen;
	}
	return *this;
}

void Examen::citire(istream& in) {
	cout << "Materie: ";
	getline(in, materie);
	cout << "Nota scris: ";
	in >> nota_scris;
	in.get();
}
void Examen::afisare(ostream& out) const {
	cout << "\nID Examen: ";
	out << id_examen;
	cout << "\nMaterie: ";
	out << materie;
	cout << "\nNota scris: ";
	out << nota_scris;
}
istream& operator>>(istream& in, Examen& E) {
	E.citire(in);
	return in;
}
ostream& operator<<(ostream& out, const Examen& E) {
	E.afisare(out);
	return out;
}

// ------------------------------------------------------- PARTIAL ----------------------------------------------

class Partial :public Examen {
	int nota_oral;
public:
	Partial();
	Partial(string, int, int);
	Partial(const Partial&);
	~Partial();
	Partial& operator=(const Partial&);
	int get_nota() { return nota_oral; }
	void set_nota(int nota) { nota_oral = nota; }
	void citire(istream&);
	void afisare(ostream&) const;
	friend istream& operator>>(istream&, Partial&);
	friend ostream& operator<<(ostream&, const Partial&);
};
Partial::Partial() :Examen() {
	nota_oral = 0;
}
Partial::Partial(string m, int nota1, int nota2) : Examen(m, nota1) {
	nota_oral = nota2;
}
Partial::Partial(const Partial& P) : Examen(P) {
	nota_oral = P.nota_oral;
}
Partial::~Partial() {
	nota_oral = 0;
}
Partial& Partial::operator=(const Partial& P) {
	if (this != &P) {
		Examen::operator=(P);
		this->nota_oral = P.nota_oral;
	}
	return *this;
}
void Partial::citire(istream& in) {
	Examen::citire(in);
	cout << "Nota oral: ";
	in >> nota_oral;
}
void Partial::afisare(ostream& out) const {
	Examen::afisare(out);
	cout << "\nNota oral: ";
	out << nota_oral;
}
istream& operator>>(istream& in, Partial& P) {
	P.citire(in);
	return in;
}
ostream& operator<<(ostream& out, const Partial& P) {
	P.afisare(out);
	return out;
}

// ------------------------------------------------------- FINAL -----------------------------------------------------

class Final :public Examen {
	int puncte;
public:
	Final();
	Final(string, int, int);
	Final(const Final&);
	~Final();
	Final& operator=(const Final&);
	void citire(istream&);
	void afisare(ostream&) const;
	friend istream& operator>>(istream&, Final&);
	friend ostream& operator<<(ostream&, const Final&);
};
Final::Final() : Examen() {
	puncte = 0;
}
Final::Final(string m, int n_s, int p) : Examen(m, n_s) {
	puncte = p;
}
Final::Final(const Final& F) : Examen(F) {
	puncte = F.puncte;
}
Final::~Final() {
	puncte = 0;
}
Final& Final::operator=(const Final& F) {
	if (this != &F) {
		Examen::operator=(F);
		this->puncte = F.puncte;
	}
	return *this;
}
void Final::citire(istream& in) {
	Examen::citire(in);
	cout << "Puncte proiect: ";
	in >> puncte;
}
void Final::afisare(ostream& out) const {
	Examen::afisare(out);
	cout << "\nPuncte proiect: ";
	out << puncte;
}
istream& operator>>(istream& in, Final& F) {
	F.citire(in);
	return in;
}
ostream& operator<<(ostream& out, const Final& F) {
	F.afisare(out);
	return out;
}

// ------------------------------------------------------- QUIZ ---------------------------------------------------

class Quiz :public Examen {
	int nr_itemi;
public:
	Quiz();
	Quiz(string, int, int);
	Quiz(const Quiz&);
	~Quiz();
	Quiz& operator=(const Quiz&);
	void citire(istream&);
	void afisare(ostream&) const;
	friend istream& operator>>(istream&, Quiz&);
	friend ostream& operator<<(ostream&, const Quiz&);
};
Quiz::Quiz() : Examen() {
	nr_itemi = 0;
}
Quiz::Quiz(string m, int nota, int nr) : Examen(m, nota) {
	nr_itemi = nr;
}
Quiz::Quiz(const Quiz& Q) : Examen(Q) {
	nr_itemi = Q.nr_itemi;
}
Quiz::~Quiz() {
	nr_itemi = 0;
}
Quiz& Quiz::operator=(const Quiz& Q) {
	if (this != &Q) {
		Examen::operator=(Q);
		this->nr_itemi = Q.nr_itemi;
	}
	return *this;
}
void Quiz::citire(istream& in) {
	Examen::citire(in);
	cout << "Nr itemi: ";
	in >> nr_itemi;
}
void Quiz::afisare(ostream& out) const {
	Examen::afisare(out);
	cout << "\nNr itemi: ";
	out << nr_itemi;
}
istream& operator>>(istream& in, Quiz& Q) {
	Q.citire(in);
	return in;
}
ostream& operator<<(ostream& out, const Quiz& Q) {
	Q.afisare(out);
	return out;
}

//---------------------------------- CATALOG_INDIVIDUAL--------------------------------------------
template <typename T>
class Catalog_Individual {
	static int contor;
	int id_student;
	string nume_student;
	vector<T> examene;
	int nr_examene;
public:
	Catalog_Individual();
	Catalog_Individual(vector<T>, int = 0, string = "");
	Catalog_Individual(const Catalog_Individual&);
	string get_nume() { return nume_student; }
	~Catalog_Individual();
	Catalog_Individual<T>& operator=(const Catalog_Individual<T>&);
	Catalog_Individual<T> operator+=(const Catalog_Individual<T>&);
	static void Decrease() { contor--; }
	int get_nr() { return nr_examene; }
	void citire(istream& in) {
		cout << "\nNume: ";
		try {
			string nume;
			getline(in, nume);
			for (unsigned i = 0; i < nume.length(); i++)
				if (nume[i] != ' ')
					if (nume[i] < 'A' || nume[i] > 'z' || (nume[i] > 'Z' && nume[i] < 'a'))
						throw 10;
			nume_student = nume;
		}
		catch (int) {
			cout << "Numele trebuie sa contina doar litere!";
			exit(1);
		}
		cout << "Nr examene: ";
		in >> nr_examene;
		in.get();
	}
	friend istream& operator>>(istream& in, Catalog_Individual<T>& catalog) {
		catalog.citire(in);
		return in;
	}
	void afisare(ostream& out) const {
		cout << "\nID student: ";
		out << id_student;
		out << '\n';
		cout << "Nume: ";
		out << nume_student;
		out << '\n';
		cout << "Nr examene: ";
		out << nr_examene;
		out << "\n";
		for (int i = 0; i < nr_examene; i++) {
			out << *examene[i] << '\n';
		}
	}
	friend ostream& operator<<(ostream& out, const Catalog_Individual<T>& catalog) {
		catalog.afisare(out);
		return out;
	}
};
template <typename T>
int Catalog_Individual<T>::contor = 0;

template <typename T>
Catalog_Individual<T>::Catalog_Individual() {
	nr_examene = 0;
	examene.resize(0);
	contor++;
	id_student = contor;
	nume_student = "";
}
template <typename T>
Catalog_Individual<T>::Catalog_Individual(vector<T> e, int nr, string nume) {
	nume_student = nume;
	nr_examene = nr;
	contor++;
	id_student = contor;
	examene.resize(e.size());
	for (unsigned i = 0; i < e.size(); i++)
		examene[i] = e[i];
}
template <typename T>
Catalog_Individual<T>::Catalog_Individual(const Catalog_Individual& C) {
	nume_student = C.nume_student;
	contor++;
	id_student = C.id_student;
	nr_examene = C.nr_examene;
	examene.resize(nr_examene);
	for (int i = 0; i < nr_examene; i++)
		examene[i] = C.examene[i];
}
template <typename T>
Catalog_Individual<T>::~Catalog_Individual() {
	examene.clear();
	nr_examene = 0;
	id_student = 0;
	nume_student = "";
}
template <typename T>
Catalog_Individual<T>& Catalog_Individual<T>::operator=(const Catalog_Individual& C) {
	if (this != &C) {
		this->nume_student = C.nume_student;
		this->id_student = C.id_student;
		this->nr_examene = C.nr_examene;
		this->examene.resize(nr_examene);
		for (unsigned i = 0; i < nr_examene; i++) {
			this->examene[i] = C.examene[i];
		}
	}
	return *this;
}

template <typename T>
Catalog_Individual<T> Catalog_Individual<T>::operator+=(const Catalog_Individual<T>& catalog) {
	for (int i = 0; i < catalog.nr_examene; i++)
		this->examene.push_back(catalog.examene[i]);
	return *this;
}

//-------------------------------------------- SPECIALIZARE QUIZ ----------------------------------------

template <>
class Catalog_Individual<Quiz> {
	string nume_student;
	int nr_examene;
	vector<Quiz> examene;
	static int nr_persoane;
public:
	Catalog_Individual();
	Catalog_Individual(vector<Quiz>, int = 0, string = "");
	Catalog_Individual(const Catalog_Individual&);
	~Catalog_Individual();
	int get_nr() { return nr_examene; }
	static int get_nr_persoane() { return nr_persoane; }
	Catalog_Individual<Quiz>& operator=(const Catalog_Individual<Quiz>&);
	Catalog_Individual<Quiz> operator+=(const Catalog_Individual<Quiz>&);
	void citire(istream& in) {
		cout << "\nNume: ";
		try {
			string nume;
			getline(in, nume);
			for (unsigned i = 0; i < nume.length(); i++)
				if (nume[i] != ' ')
					if (nume[i] < 'A' || nume[i] > 'z' || (nume[i] > 'Z' && nume[i] < 'a'))
						throw 10;
			nume_student = nume;
		}
		catch (int) {
			cout << "Numele trebuie sa contina doar litere!";
			exit(1);
		}
		cout << "Nr examene: ";
		try {
			in >> nr_examene;
			in.get();
			if (nr_examene < 0)
				throw 1.5;
		}
		catch (double) {
			cout << "Numarul de examene trebuie sa fie pozitiv!";
			exit(1);
		}
		if (nr_examene > 1) {
			nr_persoane++;
		}
	}
	friend istream& operator>>(istream& in, Catalog_Individual<Quiz>& catalog) {
		catalog.citire(in);
		return in;
	}
	void afisare(ostream& out)const {
		cout << "\nNume: ";
		out << nume_student;
		out << '\n';
		cout << "Nr examene: ";
		out << nr_examene;
		out << "\n";
		for (int i = 0; i < nr_examene; i++) {
			out << examene[i] << '\n';
		}
	}
	friend ostream& operator<<(ostream& out, const Catalog_Individual<Quiz>& catalog) {
		catalog.afisare(out);
		return out;
	}
};

int Catalog_Individual<Quiz>::nr_persoane = 0;

Catalog_Individual<Quiz>::Catalog_Individual() {
	nume_student = "";
	nr_examene = 0;
	examene.resize(0);
}

Catalog_Individual<Quiz>::Catalog_Individual(vector<Quiz> e, int nr, string nume) {
	nume_student = nume;
	nr_examene = nr;
	examene.resize(e.size());
	for (unsigned i = 0; i < e.size(); i++)
		examene[i] = e[i];
}

Catalog_Individual<Quiz>::Catalog_Individual(const Catalog_Individual& C) {
	nume_student = C.nume_student;
	nr_examene = C.nr_examene;
	examene.resize(nr_examene);
	for (int i = 0; i < nr_examene; i++)
		examene[i] = C.examene[i];
}

Catalog_Individual<Quiz>::~Catalog_Individual() {
	nume_student = "";
	nr_examene = 0;
	examene.clear();
}
Catalog_Individual<Quiz>& Catalog_Individual<Quiz>::operator=(const Catalog_Individual& C) {
	if (this != &C) {
		this->nume_student = C.nume_student;
		this->nr_examene = C.nr_examene;
		this->examene.resize(nr_examene);
		for (int i = 0; i < nr_examene; i++) {
			this->examene[i] = C.examene[i];
		}
	}
	return *this;
}
Catalog_Individual<Quiz> Catalog_Individual<Quiz>::operator+=(const Catalog_Individual<Quiz>& catalog) {
	for (int i = 0; i < catalog.nr_examene; i++)
		this->examene.push_back(catalog.examene[i]);
	return *this;
}

void menu_output()
{
	cout << "\n";
	cout.width(40);
	cout << "SESIUNE FACULTATE\n";
	cout.width(65);
	cout.fill('=');
	cout << "\n\n";
	cout.width(33);
	cout.fill(' ');
	cout << "MENIU\n";
	cout << "\n1. Citeste si afiseaza informatii despre studenti. --- UPCAST & Late-Binding & Template\n";
	cout << "2. Citeste studenti si permite refacerea examenului pentru cei care au picat partialul. --- UPCAST & DOWNCAST\n";
	cout << "3. Citeste studenti care au dat doar quiz-uri si afiseaza cati au dat cel putin 2. --- Template (Specializare Quiz)\n";
	cout << "0. Iesire.\n\n";
}

void menu()
{
	vector<Catalog_Individual<Examen*>>Student;
	vector<Catalog_Individual<Quiz>>Elev;
	int optiune = 0, n;
	do {
		menu_output();
		cout << "Alegeti o comanda: ";
		cin >> optiune;
		if (optiune == 1) {
			string tip;
			cout << "Introduceti numarul de studenti: ";
			cin >> n;
			cin.get();
			Student.resize(n);
			for (int i = 0; i < n; i++) {
				cin >> Student[i];
				vector<Examen*> exams;
				for (int j = 0; j < Student[i].get_nr(); j++) {
					cout << "Alegeti tipul examenului (partial / final / quiz): ";
					cin >> tip;
					cin.get();
					try {
						if (tip == "partial") {
							Examen* p = new Partial;
							cin >> *p;
							exams.push_back(p);
						}
						else if (tip == "final") {
							Examen* p = new Final;
							cin >> *p;
							exams.push_back(p);
						}
						else if (tip == "quiz") {
							Examen* p = new Quiz;
							cin >> *p;
							exams.push_back(p);
						}
						else throw 10;
					}
					catch (bad_alloc&) {
						cout << "Allocation Failure!";
						exit(EXIT_FAILURE);
					}
					catch (int) {
						cout << "Optiune invalida.";
						exit(1);
					}
				}
				cin.get();
				Catalog_Individual<Examen*> Auxiliar(exams, Student[i].get_nr());
				Catalog_Individual<Examen*>::Decrease();
				Student[i] += Auxiliar;
			}
			cout.width(20);
			cout.fill('=');
			cout << "\n";
			for (int i = 0; i < n; i++) {
				cout << Student[i] << "\n";
			}
			cout.fill(' ');
		}
		else if (optiune == 2) {
			string tip;
			cout << "Introduceti numarul de studenti: ";
			cin >> n;
			cin.get();
			Student.resize(n);
			for (int i = 0; i < n; i++) {
				cin >> Student[i];
				vector<Examen*> exams;
				for (int j = 0; j < Student[i].get_nr(); j++) {
					cout << "Alegeti tipul examenului (partial / final / quiz): ";
					cin >> tip;
					cin.get();
					try {
						if (tip == "partial") {
							Examen* p = new Partial;
							cin >> *p;
							exams.push_back(p);
						}
						else if (tip == "final") {
							Examen* p = new Final;
							cin >> *p;
							exams.push_back(p);
						}
						else if (tip == "quiz") {
							Examen* p = new Quiz;
							cin >> *p;
							exams.push_back(p);
						}
						else throw 10;
					}
					catch (bad_alloc&) {
						cout << "Allocation Failure!";
						exit(EXIT_FAILURE);
					}
					catch (int) {
						cout << "Optiune invalida.";
						exit(1);
					}
				}
				cin.get();
				for (int k = 0; k < exams.size(); k++) {
					if (Partial* q = dynamic_cast<Partial*>(exams[k])) {
						if (q->get_nota() < 5) {
							cout << "Doriti ca " << Student[i].get_nume() << " sa dea iar examenul partial? (da / nu): ";
							string raspuns;
							getline(cin, raspuns);
							try {
								if (raspuns == "da") {
									cout << "Introduceti noua nota a examenului partial: ";
									int nota;
									cin >> nota;
									cin.get();
									q->set_nota(nota);
								}
								else if (raspuns == "nu") {
									continue;
								}
								else {
									throw 15;
								}
							}
							catch (int) {
								cout << "Optiune invalida.";
								exit(1);
							}
						}
					}
				}
				Catalog_Individual<Examen*> Auxiliar(exams, Student[i].get_nr());
				Catalog_Individual<Examen*>::Decrease();
				Student[i] += Auxiliar;

			}
			cout.width(20);
			cout.fill('=');
			cout << "\n";
			for (int i = 0; i < n; i++) {
				cout << Student[i] << "\n";
			}
			cout.fill(' ');
		}
		else if (optiune == 3) {
			string tip;
			cout << "Introduceti numarul de studenti: ";
			cin >> n;
			cin.get();
			Elev.resize(n);
			for (int i = 0; i < n; i++) {
				cin >> Elev[i];
				vector<Quiz> exam;
				for (int j = 0; j < Elev[i].get_nr(); j++) {
					Quiz x;
					cin >> x;
					exam.push_back(x);
					cin.get();
				}
				Catalog_Individual<Quiz> Aux(exam, Elev[i].get_nr());
				Elev[i] += Aux;
			}
			cout.width(20);
			cout.fill('=');
			cout << "\n";
			cout << "\nNumarul de studenti care au dat cel putin 2 quiz-uri este: " << Catalog_Individual<Quiz>::get_nr_persoane();
			cout << '\n';
			for (int i = 0; i < n; i++) {
				cout << Elev[i] << "\n";
			}
			cout.fill(' ');
		}
		else {
			cout << "\nOptiune invalida.\n";
		}
		Student.clear();
		Elev.clear();
		system("pause");
		system("cls");
	} while (optiune != 0);
}

int main()
{
	menu();
	return 0;
}
