#include "Arbore_AVL.h"
using namespace std;

Arbore_AVL::Arbore_AVL(int n, Nod_AVL* p):Arbore(n),root(p){}

Arbore_AVL::Arbore_AVL(const Arbore_AVL& A): Arbore(A){
	this->root = A.root;
}

Arbore_AVL::~Arbore_AVL(){}

Arbore_AVL& Arbore_AVL::operator=(const Arbore_AVL& A) {
	if (this != &A) {
		Arbore::operator=(A);
		this->root = A.root;
	}
	return *this;
}

Nod_AVL* Arbore_AVL::getroot() {
	return root;
}

void Arbore_AVL::setroot(Nod_AVL* p) {
    root = p;
    return;
}

void Arbore_AVL::PrintEchilibru(Nod_AVL* root) const{
    if (root != NULL)
    {   
        cout<<"Nod Info : "<< root->info<< " Factor de echilibru: "<<root->echilibru<< "\n";
        PrintEchilibru(static_cast<Nod_AVL*>(root->st));
        PrintEchilibru(static_cast<Nod_AVL*>(root->dr));
    }
}

istream& operator>>(istream& in, Arbore_AVL& A)
{
    int n, x;
    cout << "Nr noduri - Arbore AVL: ";
    in >> n;
    cout << "Elemente: ";
    for (int i = 0; i < n; i++) {
        in >> x;
        A.Insert(x);
    }
    return in;
}

void Arbore_AVL::Inorder(Nod_AVL* root, ostream& os) const {  
    
    // metoda de parcurgere in ordine a arborelui 
    
    if (root == NULL)
        return;
    else {
        Inorder(static_cast<Nod_AVL*>(root->getst()), os);
        os << root->getinfo() << " ";
        Inorder(static_cast<Nod_AVL*>(root->getdr()), os);
    }
}

ostream& operator<<(ostream& out, const Arbore_AVL& A) {
    Nod_AVL* p = A.root;
    A.Inorder(p, out);
    out<< "\n";
    return out;
}
// Adancimea
int Arbore_AVL::MaxHeight(Nod* p)
{
    if (p == NULL)
        return 0;
    else{
        int HeightLeft = MaxHeight(p->st);
        int HeightRight = MaxHeight(p->dr);
        if (HeightLeft > HeightRight)
            return(HeightLeft + 1);
        else return(HeightRight + 1);
    }
}
// Functie de determinare a echilibrului unui nod
int Arbore_AVL::BalanceFactor(Nod* T1, Nod* T2) {
    int height1, height2;
    height1 = MaxHeight(T1);
    height2 = MaxHeight(T2);
    return height2 - height1;
}

void Arbore_AVL::Insert(int key) {
    if (nr_noduri == 0) {
        root = new Nod_AVL(key);
        nr_noduri = 1;
        return;
    }
    Nod_AVL* v[101] = { NULL };
    Nod_AVL* p = new Nod_AVL(key);
    Nod_AVL* q = root;
    Nod_AVL* trail = NULL;
    int i = 0;
    while (q != NULL) {
        trail = q;
        v[++i] = q;
        if (key < q->info) {
            q = static_cast<Nod_AVL*>(q->st);
        }
        else if(key>q->info){
            q = static_cast<Nod_AVL*>(q->dr);
        }
        else {
            try {
                if (key == q->info)
                    throw key;
            }
            catch (int x) {
                cout << "Elementele trebuie sa fie distincte!";
                exit(1);
            }
        }
    }
    if (trail != NULL) {
        if (key < trail->info)
            trail->st = p;
        else
            trail->dr = p;
    }
    v[++i] = p;
    nr_noduri++;
    i -= 1;
    while (i) {
        v[i]->echilibru = BalanceFactor(v[i]->st, v[i]->dr);
        if (v[i]->echilibru < -1 ){
            if (v[i + 1]->info > key) {    // Left Left Rotation
                Nod* temp1 = v[i + 2]->st;
                Nod* temp2 = v[i + 2]->dr;
                Nod* temp3 = v[i + 1]->dr;
                Nod* temp4 = v[i]->dr;

                int aux = v[i]->info;
                v[i]->info = v[i + 1]->info;
                v[i + 1]->info = aux;
                v[i]->dr = v[i]->st;
                v[i]->st = v[i + 1]->st;
                v[i + 1]->st =  temp3;
                v[i + 1]->dr = temp4;
                v[i + 1]->echilibru = BalanceFactor(v[i+1]->st,v[i+1]->dr);
                v[i]->echilibru = BalanceFactor(v[i]->st,v[i]->dr);
                v[i + 2]->echilibru = BalanceFactor(v[i + 2]->st, v[i + 2]->dr);
            }
            else {      // Left Right Rotation
                // Left 
                Nod* temp1 = v[i + 1]->st;
                Nod* temp2 = v[i + 2]->st;
                Nod* temp3 = v[i + 2]->dr;
                Nod* temp4 = v[i]->dr;
                int aux = v[i + 1]->info;
                v[i + 1]->info = v[i + 2]->info;
                v[i + 2]->info = aux;
                v[i + 1]->st = v[i + 1]->dr;
                v[i + 1]->dr = temp3;
                v[i + 2]->st = temp1;
                v[i + 2]->dr = temp2;
                v[i + 1]->echilibru = BalanceFactor(v[i + 1]->st, v[i + 1]->dr);
                v[i + 2]->echilibru = BalanceFactor(v[i + 2]->st, v[i + 2]->dr);
                //Right
                temp3 = v[i + 1]->dr;
                aux = v[i]->info;
                v[i]->info = v[i + 1]->info;
                v[i + 1]->info = aux;
                v[i]->dr = v[i]->st;
                v[i]->st = v[i + 1]->st;
                v[i + 1]->st = temp3;
                v[i + 1]->dr = temp4;
                v[i]->echilibru = BalanceFactor(v[i]->st, v[i]->dr);
                v[i + 1]->echilibru = BalanceFactor(v[i + 1]->st, v[i + 1]->dr);
                v[i + 2]->echilibru = BalanceFactor(v[i + 2]->st, v[i + 2]->dr);
            }

        }
        if (v[i]->echilibru > 1) {
            if (v[i + 1]->info > key) {     //Right Left Rotation
                //Right
                Nod* temp1 = v[i + 1]->dr;
                Nod* temp2 = v[i + 2]->st;
                Nod* temp3 = v[i + 2]->dr;
                Nod* temp4 = v[i]->st;
                int aux = v[i + 1]->info;
                v[i + 1]->info = v[i + 2]->info;
                v[i + 2]->info = aux;
                v[i + 1]->dr = v[i + 2];
                v[i + 1]->st = temp2;
                v[i + 2]->dr = temp1;
                v[i + 2]->st = temp3;
                v[i + 1]->echilibru = BalanceFactor(v[i+1]->st,v[i+1]->dr);
                v[i + 2]->echilibru = BalanceFactor(v[i + 2]->st, v[i + 2]->dr);
                //Left
                temp1 = v[i + 1]->dr;
                temp2 = v[i + 1]->st;
                aux = v[i]->info;
                v[i]->info = v[i + 1]->info;
                v[i + 1]->info = aux;
                v[i]->st = v[i]->dr;
                v[i]->dr = temp1;
                v[i + 1]->st = temp4;
                v[i + 1]->dr = temp2;
                v[i]->echilibru = BalanceFactor(v[i]->st, v[i]->dr);
                v[i + 1]->echilibru = BalanceFactor(v[i + 1]->st, v[i + 1]->dr);
                v[i + 2]->echilibru = BalanceFactor(v[i + 2]->st, v[i + 2]->dr);
            }
            else {      // Right Right Rotation
                Nod* temp1 = v[i]->st;
                Nod* temp2 = v[i + 1]->st;
                Nod* temp3 = v[i + 2]->st;
                Nod* temp4 = v[i + 2]->dr;
                int aux = v[i]->info;
                v[i]->info = v[i + 1]->info;
                v[i + 1]->info = aux;
                v[i]->st = v[i]->dr;
                v[i]->dr = v[i + 1]->dr;
                v[i + 1]->st = temp1;
                v[i + 1]->dr = temp2;
                v[i]->echilibru = BalanceFactor(v[i]->st, v[i]->dr);
                v[i + 1]->echilibru = BalanceFactor(v[i + 1]->st, v[i + 1]->dr);
                v[i + 2]->echilibru = BalanceFactor(v[i + 2]->st, v[i + 2]->dr);
            }
        }
        i--;
    }
}