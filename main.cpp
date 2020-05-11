#include <iostream>

using namespace std;

class Nod
{
    protected:
        int info;
        Nod *stanga;
        Nod *dreapta;
        Nod *parinte;

    public:
        Nod(int i=0, Nod *st=nullptr, Nod *dr=nullptr, Nod *pr=nullptr){info = i; stanga = st; dreapta = dr; parinte = pr;}
        Nod(const Nod& nodd);
        ~Nod(){cout<<"Nod distrus\n";};
        Nod& operator =(const Nod &q);
        friend ostream& operator <<(ostream&, Nod&);
        friend istream& operator >>(istream&, Nod&);
        int get_info(){return info;};
        Nod *get_st (){return stanga;};
        Nod *get_dr (){return dreapta;};
        Nod *get_par (){return parinte;};
        void set_info(int inf){info = inf;};
        void set_st(Nod *st){stanga = st;};
        void set_dr(Nod *dr){dreapta = dr;};
        void set_par(Nod *par){parinte = par;};
};


Nod::Nod(const Nod& nodd)
{
    info = nodd.info;
    stanga = nodd.stanga;
    dreapta = nodd.dreapta;
}

ostream& operator <<(ostream& out, Nod &n)
{
    out << "Nodul are cheia: " << n.info << "\n" << "Copii:  ";
    if(n.stanga == nullptr && n.dreapta == nullptr)
    {
        out << "Frunze\n\n";
    }
    else
    {
        out << n.stanga -> info << " ,  " << n.dreapta -> info;
    }
    return out;
}

istream& operator >>(istream& in, Nod &n)
{
    if(&in == &cin)
    {
        cout << "Introduceti cheia pentru nod: ";
    }
    in>>n.info;
    return in;

}

Nod& Nod::operator=(const Nod &q)
{
    if (this != &q){
        this -> info = q.info;
        this -> stanga = q.stanga;
        this -> dreapta = q.dreapta;
    }

    return *this;
}


class Nod_rosu_negru:public Nod
{
    protected:
        Nod_rosu_negru *stanga;
        Nod_rosu_negru *dreapta;
        Nod_rosu_negru *parinte;
        char culoare;

    public:
        Nod_rosu_negru(char cul = 'r', int i = 0, Nod_rosu_negru *st = nullptr, Nod_rosu_negru *dr = nullptr, Nod_rosu_negru *par = nullptr ):Nod(i, st, dr){stanga = st; dreapta = dr; parinte = par; culoare = cul;}
        Nod_rosu_negru(const Nod_rosu_negru& RBN);
        ~Nod_rosu_negru(){cout<<"Nod rosu negru distrus\n";};
        Nod_rosu_negru& operator =(const Nod_rosu_negru &q);
        friend ostream& operator <<(ostream&, Nod_rosu_negru&);
        friend istream& operator >>(istream&, Nod_rosu_negru&);
        void set_culoare(char cul){this -> culoare = cul;};
        char get_culoare(){return culoare;};
        Nod_rosu_negru *get_st(){return stanga;};
        Nod_rosu_negru *get_dr(){return dreapta;};
        Nod_rosu_negru *get_par(){return parinte;};
        void set_st(Nod_rosu_negru *st){stanga = st;};
        void set_dr(Nod_rosu_negru *dr){dreapta = dr;};
        void set_par(Nod_rosu_negru *par){parinte = par;};

};


Nod_rosu_negru::Nod_rosu_negru(const Nod_rosu_negru& RBN):Nod(RBN)
{
    this -> stanga = RBN.stanga;
    this -> dreapta  = RBN.dreapta;
    this -> parinte = RBN.parinte;
    this -> culoare = RBN.culoare;
}

ostream& operator <<(ostream& out, Nod_rosu_negru &n)
{
    out << "Nodul RB are cheia: " << n.info;
    if(n.culoare == 'r')
    {
        out <<" si culoarea Rosie";
    }
    else if(n.culoare == 'n')
    {
        out <<" si culoarea Neagra";
    }
    else out <<" si are culoare INCORECTA\n";
    if(n.parinte != nullptr)
    {
        out << " are parinte pe " << n.parinte -> info;
    }
    else out << " este radacina";
    if(n.dreapta == nullptr && n.stanga == nullptr)
    {
        out << " si nu are copii \n";
    }
    else
    if(n.dreapta == nullptr)
    {
        out << " si are copil stanga pe " << n.stanga -> info << "\n";
    }
    else
    if(n.stanga == nullptr)
    {
        out << " si are copil dreapta pe " << n.dreapta -> info << "\n";
    }
    else
    {
        out<< " si are copii pe "<< n.stanga -> info << " si pe " << n.dreapta -> info << "\n";
    }
    return out;
}

istream& operator >>(istream& in, Nod_rosu_negru &n)
{
    if(&in == &cin)
    {
        cout << "Introduceti cheia pentru nod: ";
    }
    in>>n.info;
    if(&in == &cin)
    {
        cout << "Introduceti culoarea pentru nod: ";
    }
    in>>n.culoare;
    return in;

}

Nod_rosu_negru& Nod_rosu_negru::operator=(const Nod_rosu_negru &q)
{
    if (this != &q){
        this -> culoare = q.culoare;
        this -> info = q.info;
        this -> stanga = q.stanga;
        this -> dreapta = q.dreapta;
        this -> parinte = q.parinte;
    }

    return *this;
}

class Arbore
{
    protected:
        int nr_noduri;

    public:
        Arbore(int nr_n = 0){nr_noduri = nr_n;}
        void set_nr_noduri(int nr_n = 0){nr_noduri = nr_n;}
        int get_nr_noduri(){return nr_noduri;}
        friend ostream& operator << (ostream&, Arbore&);
        friend istream& operator >> (istream&, Arbore&);

        virtual void afis(Nod_rosu_negru* = nullptr) = 0;
        virtual void inserare(int) = 0;
        virtual void cautare(int) = 0;
};

istream& operator >>(istream &in, Arbore &arb)
{
    int i;
    int x;
    for(i = 0; i < arb.nr_noduri; i++)
    {
        in >> x;
        arb.inserare(x);
    }
    return in;
}

ostream& operator <<(ostream &out, Arbore &arb)
{
    arb.afis();
    return out;
}



class Arbore_bicolor:public Arbore
{
    protected:
        Nod_rosu_negru *radacina;
        int i;

    public:
        Arbore_bicolor(Nod_rosu_negru* radacina = nullptr, int i = 0){this -> radacina = radacina; this -> i = i;}
        ~Arbore_bicolor(){cout<<"Arbore bicolor distrus\n";};
        Nod_rosu_negru* get_radacina(){return this -> radacina;}
        void inserare(int);
        Nod_rosu_negru* inserare(Nod_rosu_negru*, Nod_rosu_negru*);
        void cautare(int);
        int cautare(int, Nod_rosu_negru *);
        Arbore_bicolor(int n) : Arbore(i){radacina = nullptr, i = 0;}
        friend ostream& operator <<(ostream&, Arbore_bicolor&);
        void afisare();
        void afis(Nod_rosu_negru*);
        void succesor(int x);
        void succ(int x, long long int &k , Nod_rosu_negru * pt);
        void predecesor(int x);
        void pred(int x, long long int &k , Nod_rosu_negru * pt);
        void rotire_stanga(Nod_rosu_negru*, Nod_rosu_negru*);
        void rotire_dreapta(Nod_rosu_negru*, Nod_rosu_negru*);
        void fix_incalcare(Nod_rosu_negru*, Nod_rosu_negru*);
        int adancime(Nod_rosu_negru*);
        int max(int a, int b);

void Arbore_bicolor :: inserare(int data)
{
    i++;
    Nod_rosu_negru *nod = new Nod_rosu_negru('r', data);
    radacina = inserare(radacina, nod);
    cout << "Nodul cu cheia " << data << " a fost inserat\n";
    fix_incalcare(radacina, nod);
}


Nod_rosu_negru* Arbore_bicolor :: inserare(Nod_rosu_negru* radacina, Nod_rosu_negru* data)
{

    if(radacina == nullptr)
    {
        return data;
    }
    if (data -> get_info() < radacina -> get_info())
    {
        radacina -> set_st(inserare(radacina -> get_st(), data));
        radacina -> get_st() -> set_par(radacina);
    }
    else
    if (data -> get_info() > radacina -> get_info())
    {
        radacina -> set_dr(inserare(radacina -> get_dr(), data));
        radacina -> get_dr() -> set_par(radacina);
    }

    return radacina;
}


ostream& operator <<(ostream& out, Arbore_bicolor& x)
{
        out << "Apelare operator <<\n";
        x.afisare();
        return out;
}

void Arbore_bicolor::afisare()
{
    afis(radacina);
}

void Arbore_bicolor :: afis(Nod_rosu_negru* x)
{

    if(x != nullptr)
        {
            afis(x -> get_st());
            cout << *x;
            afis(x -> get_dr());
        }
}

istream& operator >>(istream& in, Arbore_bicolor &arb)
{
    int n;
    if(&in == &cin)
    {
        cout << "Numarul de noduri: ";
    }
    in>>n;
    for(int i = 0; i < n; i++)
    {
        int n_citit;
        if(&in == &cin)
        {
            cout << "Introduceti cheia pentru nod: ";
        }
        in >> n_citit;
        arb.inserare(n_citit);
    }
    return in;

}

void Arbore_bicolor :: cautare(int x)
{
    int n;
    n = cautare(x, radacina);
    if(n == 0)
    {
        cout << "Nodul " << x << " nu exista\n";
    }
    else
    {
        cout << "Nodul " << x << " exista\n";
    }

}


int Arbore_bicolor :: cautare(int k, Nod_rosu_negru *radacina)
{
    Nod_rosu_negru *pt = radacina;
    int ok = 0;
    while(pt != nullptr && ok == 0)
    {
        if(pt -> get_info() == k)
        {
            ok = 1;
        }
        if(ok == 0)
        {
            if(pt -> get_info() < k)
            {
                pt = pt -> get_dr();
            }
            else
            {
                pt = pt -> get_st();
            }
        }
    }

    return ok;
}


void Arbore_bicolor :: succ(int x, long long int & k, Nod_rosu_negru * pt)
{
    if (pt != nullptr)
    {
        succ(x, k, pt -> get_st());
        if (pt -> get_info() > x && pt -> get_info() < k)
        {
            k = pt -> get_info();
        }
        succ(x, k, pt -> get_dr());
    }
}

void Arbore_bicolor :: succesor(int x)
{
    int ok = cautare(x, radacina);
    if(ok == 0)
    {
        cout << "Nodul nu exista\n";
    }
    else
    {
        long long int k = 9223372036854775807;
        succ(x, k, radacina);
        if (k == 9223372036854775807)
        {
            cout << "Nu exista succesor pentru nodul " << x << "\n";
        }
        else
        {
            cout << "Succesorul nodului " << x << " este " << k << "\n";
        }
    }

}

void Arbore_bicolor :: pred(int x, long long int & k, Nod_rosu_negru * pt)
{
    if (pt != nullptr)
    {
        pred(x, k, pt -> get_st());
        if (pt -> get_info() < x && pt -> get_info() > k)
        {
            k = pt -> get_info();
        }
        pred(x, k, pt -> get_dr());
    }
}

void Arbore_bicolor :: predecesor(int x)
{
    int ok = cautare(x, radacina);
    if(ok == 0)
    {
        cout << "Nodul nu exista\n";
    }
    else
    {
        long long int k = -9223372036854775807;
        pred(x, k, radacina);
        if (k == -9223372036854775807)
        {
            cout << "Nu exista predecesor pentru nodul " << x << "\n";
        }
        else
        {
            cout << "Predecesor nodului " << x << " este " << k << "\n";
        }
    }

}



void Arbore_bicolor :: rotire_stanga(Nod_rosu_negru * rad, Nod_rosu_negru * pt)
{

    cout << "rotire_stanga\n";
    Nod_rosu_negru * pt_dreapta = pt -> get_dr();

    pt -> set_dr(pt_dreapta -> get_st());
    if(pt -> get_dr() != nullptr)
    {
        pt -> get_dr() -> set_par(pt);
    }

    pt_dreapta -> set_par(pt -> get_par());

    if(pt -> get_par() == nullptr)
    {
        radacina = pt_dreapta;
    }

    else
    if (pt == pt -> get_par() -> get_st())
    {
        pt -> get_par() -> set_st(pt_dreapta);
    }
    else
    {
        pt -> get_par() -> set_dr(pt_dreapta);
    }

    pt_dreapta -> set_st(pt);
    pt -> set_par(pt_dreapta);
}

void Arbore_bicolor :: rotire_dreapta(Nod_rosu_negru * rad, Nod_rosu_negru * pt)
{

    cout << "rotire_dreapta\n";
    Nod_rosu_negru * pt_stanga = pt -> get_st();

    pt -> set_st(pt_stanga -> get_dr());
    if(pt -> get_st() != nullptr)
    {
        pt -> get_st() -> set_par(pt);
    }

    pt_stanga -> set_par(pt -> get_par());

    if(pt -> get_par() == nullptr)
    {
        radacina = pt_stanga;
    }

    else
    if (pt == pt -> get_par() -> get_st())
    {
        pt -> get_par() -> set_st(pt_stanga);
    }
    else
    {
        pt -> get_par() -> set_dr(pt_stanga);
    }

    pt_stanga -> set_dr(pt);
    pt -> set_par(pt_stanga);
}

void Arbore_bicolor :: fix_incalcare(Nod_rosu_negru * rad, Nod_rosu_negru * pt)
{
    cout << "fix_incalcare\n";
    Nod_rosu_negru *prt = new Nod_rosu_negru;
    Nod_rosu_negru *bunic = new Nod_rosu_negru;
    Nod_rosu_negru *aux = new Nod_rosu_negru;
    while ((pt != radacina) && (pt -> get_culoare() != 'n') && (pt -> get_par() -> get_culoare() == 'r'))
    {
        prt = pt -> get_par();
        bunic = pt -> get_par()->get_par();


        if (prt == bunic -> get_st())
        {
            Nod_rosu_negru *unchi = bunic -> get_dr();

            if (unchi != nullptr && unchi -> get_culoare() == 'r')
            {
                bunic->set_culoare('r');
                prt->set_culoare('n');
                unchi->set_culoare('n');
                pt = bunic;
            }
            else
            {
                if (pt == prt->get_dr())
                {
                    rotire_stanga(radacina, prt);
                    pt = prt;
                    prt = pt->get_par();
                }
                rotire_dreapta(radacina, bunic);
                aux -> set_culoare(bunic -> get_culoare());
                bunic -> set_culoare(prt -> get_culoare());
                prt -> set_culoare(aux -> get_culoare());
                pt = prt;
            }
        }

        else
        {
            Nod_rosu_negru *unchi = bunic->get_st();

            if ((unchi != nullptr) && (unchi -> get_culoare() == 'r'))
            {
                bunic->set_culoare('r');
                prt->set_culoare('n');
                unchi->set_culoare('n');
                pt = bunic;
            }
            else
            {
                if (pt == prt->get_st())
                {
                    rotire_dreapta(radacina, prt);
                    pt = prt;
                    prt = pt -> get_par();
                }
                rotire_stanga(radacina, bunic);
                aux -> set_culoare(bunic -> get_culoare());
                bunic -> set_culoare(prt -> get_culoare());
                prt -> set_culoare(aux -> get_culoare());
                pt = prt;
            }
        }
    }

    radacina -> set_culoare('n');
}

int Arbore_bicolor :: adancime(Nod_rosu_negru *x)
{
    if(x == nullptr)
    {
        return -1;
    }
    else
    {
        return max(adancime(x -> get_st()), adancime(x -> get_dr())) +1;
    }
}



int Arbore_bicolor :: max(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}






int main()
{

/*Nod_rosu_negru nupp;
cin >> nupp;
cout << nupp;
Nod_rosu_negru test;
test = nupp;
cout << test;
*/
/*
Nod_rosu_negru noddd('r', 7);
cout << noddd;
Arbore_bicolor *arb;
arb -> inserare(6);
arb -> inserare(8);
arb -> cautare(6);
cout << arb;
*/

Arbore_bicolor  arb(9);
Nod_rosu_negru nrn(7);
arb.inserare(1);
arb.cautare(321);
cout << arb;
arb.cautare(1);
Nod_rosu_negru *k = arb.get_radacina();
arb.succesor(7);
arb.predecesor(8);
int n = arb.adancime(k);
cout << "\nAdancimea arborelui : " << n << "\n";

return 0;
}
