#include <iostream>
#include <cstring>
using namespace std;

class Meniu
{
public:
    virtual void printMeniu() = 0;
    virtual int getPrice() = 0;
    virtual bool getOptiuni()
    {
        return false;
    }
    virtual int getCantitate()
    {
        return 1;
    }
    virtual bool getMeniu(const char *input)
    {
        return false;
    }

    virtual ~Meniu() {}
};

class CiorbaDeBurta : public Meniu
{
    const char *Nume;
    int Pret;
    const char *Optiune1;
    const char *Optiune2;
    int PretOptiune1;
    int PretOptiune2;
    bool Optiuni;

public:
    CiorbaDeBurta()
    {
        Nume = "Ciorba de burta";
        Pret = 15;
        PretOptiune1 = 3;
        PretOptiune2 = 2;
        Optiune1 = "Smantana";
        Optiune2 = "Ardei";
        Optiuni = true;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }

    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }

    int getPrice()
    {
        return Pret;
    }

    bool getOptiuni()
    {
        return Optiuni;
    }
};
class CiorbaDeLegume : public Meniu
{
    const char *Nume;
    int Pret;
    bool Optiuni;
    const char *Optiune1;
    const char *Optiune2;
    int PretOptiune1;
    int PretOptiune2;

public:
    CiorbaDeLegume()
    {
        Nume = "Ciorba de legume";
        Pret = 10;
        Optiuni = true;
        PretOptiune1 = 3;
        PretOptiune2 = 2;
        Optiune1 = "Smantana";
        Optiune2 = "Ardei";
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }

    int getPrice()
    {
        return Pret;
    }
    bool getOptiuni()
    {
        return Optiuni;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class CiorbaDeCiuperci : public Meniu
{
    const char *Nume;
    int Pret;
    bool Optiuni;

public:
    CiorbaDeCiuperci()
    {
        Nume = "Ciorba de ciuperci";
        Pret = 12;
        Optiuni = false;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }

    int getPrice()
    {
        return Pret;
    }
    bool getOptiuni()
    {
        return Optiuni;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};

class VitaFile : public Meniu
{
    const char *Nume;
    int Pret;
    bool Optiuni;
    int Cantitate;

public:
    VitaFile()
    {
        Nume = "Vita file";
        Pret = 35;
        Optiuni = 1;
        Cantitate = 100;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class VitaStroganoff : public Meniu
{
    const char *Nume;
    int Pret;
    bool Optiuni;
    int Cantitate;

public:
    VitaStroganoff()
    {
        Nume = "Vita stroganoff";
        Pret = 45;
        Optiuni = 1;
        Cantitate = 100;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class TocanaDePui : public Meniu
{
    const char *Nume;
    int Pret;
    bool Optiuni;
    int Cantitate;

public:
    TocanaDePui()
    {
        Nume = "Tocana de pui";
        Pret = 30;
        Optiuni = 0;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class FrigaruiDePui : public Meniu
{
    const char *Nume;
    int Pret;
    bool Optiuni;
    int Cantitate;

public:
    FrigaruiDePui()
    {
        Nume = "Frigarui de pui";
        Pret = 25;
        Optiuni = 0;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};

class CartofiPrajiti : public Meniu
{
    const char *Nume;
    int Pret;

public:
    CartofiPrajiti()
    {
        Nume = "Cartofi prajiti";
        Pret = 15;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class PiureDeCartofi : public Meniu
{
    const char *Nume;
    int Pret;

public:
    PiureDeCartofi()
    {
        Nume = "Piure de cartofi";
        Pret = 10;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class Orez : public Meniu
{
    const char *Nume;
    int Pret;

public:
    Orez()
    {
        Nume = "Orez";
        Pret = 5;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};

class VinCB2004 : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    VinCB2004()
    {
        Nume = "Vin Castel Bolovanu 2004";
        Pret = 55;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class VinB1996 : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    VinB1996()
    {
        Nume = "Vin Bordeaux 1996";
        Pret = 60;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class VinAlb : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    VinAlb()
    {
        Nume = "Vin alb";
        Pret = 14;
        Cantitate = 100;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class VinRosu : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    VinRosu()
    {
        Nume = "Vin rosu";
        Pret = 15;
        Cantitate = 100;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class ApaMinerala : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    ApaMinerala()
    {
        Nume = "Apa minerala";
        Pret = 5;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class ApaPlata : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    ApaPlata()
    {
        Nume = "Apa plata";
        Pret = 5;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};

class Inghetata : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    Inghetata()
    {
        Nume = "Inghetata";
        Pret = 10;
        Cantitate = 1;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};
class TortKranz : public Meniu
{
    const char *Nume;
    int Pret;
    int Cantitate;

public:
    TortKranz()
    {
        Nume = "Tort Kranz";
        Pret = 20;
        Cantitate = 0;
    }

    void printMeniu()
    {
        cout << Nume << " " << Pret << "lei" << endl;
    }
    int getPrice()
    {
        return Pret;
    }

    int getCantitate()
    {
        return Cantitate;
    }
    bool getMeniu(const char *input)
    {
        if (strcmp(input, Nume) == 0)
            return true;
        return false;
    }
};

class Restaurant
{
    int NumarMese;

public:
    Restaurant(int numarMese)
    {
        NumarMese = numarMese;
    }
    int getNrMese()
    {
        return NumarMese;
    }
    ~Restaurant()
    {
        delete this;
    }
};

class Mese
{
protected:
    int NumarMasa;
    int NumarLocuri;
    int Nota;
    bool Ocupata;
    Mese *next;
    Mese *start;

public:
    Mese()
    {
        NumarMasa = 0;
        NumarLocuri = 0;
        Ocupata = false;
        Nota = 0;
        next = nullptr;
        start = nullptr;
    }
    Mese(const Mese &other)
    {
        this->NumarMasa = other.NumarMasa;
        this->NumarLocuri = other.NumarLocuri;
        this->Ocupata = other.Ocupata;
        this->Nota = other.Nota;
        this->next = other.next;
        this->start = other.start;
    }
    Mese &operator=(const Mese &other)
    {
        if (this == addressof(other))
            return *this;
        this->NumarMasa = other.NumarMasa;
        this->NumarLocuri = other.NumarLocuri;
        this->Ocupata = other.Ocupata;
        this->Nota = other.Nota;
        this->next = other.next;
        this->start = other.start;
        return *this;
    }
    void setMasa(Mese *&masa, int seats)
    {
        Mese *p = new Mese();
        Mese *q = start;
        next = p;
        p->NumarMasa = NumarMasa++ + 1;
        p->NumarLocuri = seats;
        p->Ocupata = false;
        p->Nota = 0;
        p->next = start;
        start = p;
    }
    void OcupaMasa(int valid)
    {
        Mese *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa == valid)
            {

                p->Ocupata = true;
            }
            p = p->next;
        }
    }

    void updateNota(int nota, int masa)
    {
        Mese *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa == masa)
            {
                p->Nota -= nota;
            }
            p = p->next;
        }
    }
    int getNota(int nrmasa)
    {
        Mese *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa == nrmasa)
            {
                int nota = p->Nota;
                p->Nota = 0;
                p->Ocupata = false;
                return nota;
            }
            p = p->next;
        }
        return 0;
    }

    void printMese()
    {
        Mese *p = start;
        while (p != nullptr)
        {
            cout << "Masa " << p->NumarMasa << " cu " << p->NumarLocuri << " locuri este " << (p->Ocupata ? "ocupata" : "libera") << endl;
            p = p->next;
        }
    }
    int getMasa(int nrclienti, Mese *&start)
    {
        int masa = -1;
        int nrlocuri = -1;
        Mese *p = start;
        while (p != nullptr)
        {
            if (masa != -1 and p->NumarLocuri >= nrclienti and p->Ocupata == false and nrlocuri > p->NumarLocuri)
            {
                masa = p->NumarMasa;
                nrlocuri = p->NumarLocuri;
            }
            else if (masa == -1 and p->NumarLocuri >= nrclienti and p->Ocupata == false)
            {
                masa = p->NumarMasa;
                nrlocuri = p->NumarLocuri;
            }
            p = p->next;
        }

        return masa;
    }
    void setNota(int nota, int NumarMasa)
    {
        Mese *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa == NumarMasa)
            {
                p->Nota += nota;
                break;
            }
            p = p->next;
        }
    }

    ~Mese()
    {

        delete next;
        delete start;
    }
    friend class Clienti;
};

class Clienti
{
    int NumarMasa;
    int IdClient;
    int NotaIndividuala;
    Clienti *next;
    Clienti *start;
    Mese *masa;

public:
    Clienti()
    {
        IdClient = 0;
        NumarMasa = 0;
        NotaIndividuala = 0;
        next = nullptr;
        start = nullptr;
    }

    Clienti(const Clienti &other)
    {
        this->IdClient = other.IdClient;
        this->NumarMasa = other.NumarMasa;
        this->NotaIndividuala = other.NotaIndividuala;
        this->next = other.next;
        this->start = other.start;
    }

    Clienti &operator=(Clienti &other)
    {
        if (this == addressof(other))
            return *this;

        this->IdClient = other.IdClient;
        this->NumarMasa = other.NumarMasa;
        this->NotaIndividuala = other.NotaIndividuala;
        this->next = other.next;
        this->start = other.start;

        return *this;
    }

    void setClienti(int idClient, int numarMasa)
    {
        Clienti *p = new Clienti();
        Clienti *q = start;
        next = p;
        p->IdClient = idClient + 1;
        p->NumarMasa = numarMasa;
        p->NotaIndividuala = 0;
        p->next = start;
        start = p;
    }

    void setNotaIndividuala(int nota, int IdClient, int NumarMasa)
    {
        Clienti *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa == NumarMasa and p->IdClient == IdClient)
            {
                p->NotaIndividuala += nota;
                break;
            }
            p = p->next;
        }
    }
    void getNota()
    {
        cout << "Nota este: " << masa->Nota << endl;
    }
    int getNotaIndividuala(int id, int masa)
    {
        Clienti *p = start;
        while (p != nullptr)
        {
            if (p->IdClient == id and p->NumarMasa == masa)
            {
                int nota = p->NotaIndividuala;
                return nota;
            }
            p = p->next;
        }
        return 0;
    }

    void printClientiNota()
    {
        Clienti *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa != 0)
            {
                cout << "Clientul " << p->IdClient << " a fost asezat la masa " << p->NumarMasa << " si are nota " << p->NotaIndividuala << endl;
                p = p->next;
            }
        }
    }
    void updateNotaGrup(int masa)
    {
        Clienti *p = start;
        while (p != nullptr)
        {
            if (p->NumarMasa == masa)
            {
                p->NotaIndividuala = 0;
                p->NumarMasa = 0;
                p = p->next;
                next = nullptr;
            }
            else
            {
                p = p->next;
            }
        }
    }
    void updateNotaIndividuala(int nota, int id, int masa)
    {
        Clienti *p = start;
        while (p != nullptr)
        {
            if (p->IdClient == id and p->NumarMasa == masa)
            {
                p->NotaIndividuala = 0;
            }
            p = p->next;
        }
    }
    void verifyClient(int id, int masa)
    {
        Clienti *p = start;
        while (p != nullptr)
        {
            if (p->IdClient == id and p->NumarMasa == masa)
            {
                return;
            }
            p = p->next;
        }
        throw "Clientul nu exista!";
        return;
    }
    ~Clienti()
    {
        delete next;
        delete start;
    }
};

Meniu *LoadMenu()

{
    CiorbaDeBurta ciorbaDeBurta;
    CiorbaDeLegume ciorbaDeLegume;
    CiorbaDeCiuperci ciorbaDeCiuperci;
    VitaFile vitaFile;
    VitaStroganoff vitaStroganoff;
    TocanaDePui tocanaDePui;
    FrigaruiDePui frigaruiDePui;
    CartofiPrajiti cartofiPrajiti;
    PiureDeCartofi piureDeCartofi;
    Orez orez;
    VinCB2004 vinCB2004;
    VinB1996 vinB1996;
    VinAlb vinAlb;
    VinRosu vinRosu;
    ApaMinerala apaMinerala;
    ApaPlata apaPlata;
    Inghetata inghetata;
    TortKranz tortKranz;

    Meniu *meniu[18] = {&ciorbaDeBurta, &ciorbaDeLegume, &ciorbaDeCiuperci, &vitaFile, &vitaStroganoff, &tocanaDePui, &frigaruiDePui, &cartofiPrajiti, &piureDeCartofi, &orez, &vinCB2004, &vinB1996, &vinAlb, &vinRosu, &apaMinerala, &apaPlata, &inghetata, &tortKranz};

    return *meniu;
}
