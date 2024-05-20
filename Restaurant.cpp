#include <iostream>
#include "Restaurant1.hpp"
using namespace std;
ostream &operator<<(ostream &COUT, Clienti *clienti)
{
    clienti->printClientiNota();
    return COUT;
}

Mese *InitializareMese(Restaurant *restaurant, Mese *masa)
{

    for (int i = 0; i < restaurant->getNrMese(); i++)
    {
        cout << "Introduceti numarul de locuri pentru masa " << i + 1 << endl;
        int locuri;
        cin >> locuri;
        masa->setMasa(masa, locuri);
    }

    return masa;
}

Mese *NrMese(Mese *masa)
{
    cout << "Introduceti numarul de mese: " << endl;
    int numarMese;
    cin >> numarMese;
    Restaurant *restaurant = new Restaurant(numarMese);
    InitializareMese(restaurant, masa);
    return masa;
}

Clienti *AdaugaClienti(Mese *&masa, Clienti *&clienti)
{
    cout << "Introduceti numarul de clienti: " << endl;
    int numarClienti;
    cin >> numarClienti;

    int validMasa = masa->getMasa(numarClienti, masa);
    if (validMasa == -1)
    {
        cout << "Toate mesele sunt ocupate" << endl;
    }
    else
    {
        cout << endl;
        cout << "--------------------------------" << endl;
        cout << "Masa " << validMasa << " a fost ocupata cu succes!" << endl;
        cout << "--------------------------------" << endl;

        for (int i = 0; i < numarClienti; i++)
        {
            masa->OcupaMasa(validMasa);
            clienti->setClienti(i, validMasa);
        }
    }
    return clienti;
}

void Comanda(Meniu *meniu[], Mese *masa, Clienti *clienti)
{

    bool mp = false;
    cout << "Introduceti numarul mesei pentru care doriti sa comandati: " << endl;
    int numarMasa;
    cin >> numarMasa;
    cout << "Introduceti Id-ul Dumneaovoastra: " << endl;
    int id;
    cin >> id;

    try
    {
        clienti->verifyClient(id, numarMasa);
    }
    catch (const char *msg)
    {
        cout << msg << endl;
        return;
    }

    bool continuati;
    do
    {

        cout << "Ce ati dori sa comandati?" << endl;
        cout << "1. Ciorba" << endl;
        cout << "2. Meniu Principal" << endl;
        cout << "3. Garnitura" << endl;
        cout << "4. Bauturi" << endl;
        cout << "5. Desert" << endl;
        int optiune;
        cin >> optiune;
        switch (optiune)
        {
        case 1:
        {

            char ciorbaInput[100];

            cout << "Introduceti ciorba dorita: " << endl;

            cin.get();

            cin.getline(ciorbaInput, 98);
            bool valid = false;
            int order = 0;

            for (int i = 0; i < 3; i++)
            {
                order = i;
                valid = meniu[i]->getMeniu(ciorbaInput);
                if (valid)
                    break;
            }
            cout << valid << endl;

            if (valid)
            {

                int price = meniu[order]->getPrice();

                masa->setNota(price, numarMasa);

                clienti->setNotaIndividuala(price, id, numarMasa);

                bool optiuneCiorba = meniu[order]->getOptiuni();

                if (optiuneCiorba)
                {
                    cout << "Doriti smantana? Da/Nu" << endl;
                    char raspuns[5];
                    cin >> raspuns;
                    if ((strcmp(raspuns, "Da") == 0) || (strcmp(raspuns, "da") == 0) || (strcmp(raspuns, "DA") == 0))
                    {
                        price = 3;
                        masa->setNota(price, numarMasa);
                        clienti->setNotaIndividuala(price, id, numarMasa);
                    }
                    cout << "Doriti Ardei? Da/Nu" << endl;

                    cin >> raspuns;
                    if (strcmp(raspuns, "Da") == 0 || strcmp(raspuns, "da") == 0 || strcmp(raspuns, "DA") == 0)
                    {

                        price = 2;
                        masa->setNota(price, numarMasa);
                        clienti->setNotaIndividuala(price, id, numarMasa);
                    }
                    break;
                }
            }
            else
            {
                cout << "Ciorba nu exista in meniu" << endl;
            }
            break;
        }
        case 2:
        {
            mp = true;
            char meniuPrincipal[100];
            cout << "Introduceti meniul principal dorit: " << endl;
            cin.get();
            cin.getline(meniuPrincipal, 98);
            bool valid = false;
            int order = 0;

            for (int i = 3; i < 7; i++)
            {
                order = i;
                valid = meniu[i]->getMeniu(meniuPrincipal);
                if (valid)
                    break;
            }

            if (valid)
            {
                int cantitate = meniu[order]->getCantitate();
                if (cantitate == 0)
                {
                    int price = meniu[order]->getPrice();
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
                else
                {
                    cout << "Cantitatea dorita(/100g): " << endl;
                    int cantitateDorita;
                    cin >> cantitateDorita;
                    int price = meniu[order]->getPrice();
                    price = price * (cantitateDorita / cantitate);
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
            }
            else
            {
                cout << "Meniul principal nu exista in meniu" << endl;
            }

            break;
        }
        case 3:
        {
            if (mp == true)
            {
                char garnitura[100];
                cout << "Introduceti garnitura dorita: " << endl;
                cin.get();
                cin.getline(garnitura, 98);
                bool valid = false;
                int order = 0;

                for (int i = 7; i < 10; i++)
                {
                    order = i;
                    valid = meniu[i]->getMeniu(garnitura);
                    if (valid)
                        break;
                }

                if (valid)
                {
                    int price = meniu[order]->getPrice();
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
                else
                {
                    cout << "Garnitura nu exista in meniu" << endl;
                }
            }
            else
            {
                cout << "Nu puteti comanda garnitura fara sa comandati meniul principal" << endl;
            }

            break;
        }
        case 4:
        {
            char bauturi[100];
            cout << "Introduceti bautura dorita: " << endl;
            cin.get();
            cin.getline(bauturi, 98);
            bool valid = false;
            int order = 0;

            for (int i = 10; i < 16; i++)
            {
                order = i;
                valid = meniu[i]->getMeniu(bauturi);
                if (valid)
                    break;
            }

            if (valid)
            {
                int cantitate = meniu[order]->getCantitate();
                if (cantitate == 0)
                {
                    int price = meniu[order]->getPrice();
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
                else
                {
                    cout << "Cantitatea dorita(/100ml): " << endl;
                    int cantitateDorita;
                    cin >> cantitateDorita;
                    int price = meniu[order]->getPrice();
                    price = price * (cantitateDorita / cantitate);
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
            }
            else
            {
                cout << "Bautura nu exista in meniu" << endl;
            }

            break;
        }
        case 5:
        {
            char desert[100];
            cout << "Introduceti desertul dorit: " << endl;
            cin.get();
            cin.getline(desert, 98);
            bool valid = false;
            int order = 0;

            for (int i = 16; i < 18; i++)
            {
                order = i;
                valid = meniu[i]->getMeniu(desert);
                if (valid)
                    break;
            }

            if (valid)
            {
                int cantitate = meniu[order]->getCantitate();
                if (cantitate == 0)
                {
                    int price = meniu[order]->getPrice();
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
                else
                {
                    cout << "Cantitatea dorita(/cupa): " << endl;
                    int cantitateDorita;
                    cin >> cantitateDorita;
                    int price = meniu[order]->getPrice();
                    price = price * (cantitateDorita / cantitate);
                    masa->setNota(price, numarMasa);
                    clienti->setNotaIndividuala(price, id, numarMasa);
                }
            }
            else
            {
                cout << "Desertul nu exista in meniu" << endl;
            }

            break;
        }
        }

        cout << "Mai doriti sa comandati altceva?" << endl;
        char raspuns[5];
        cin >> raspuns;
        if (strcmp(raspuns, "Da") == 0 || strcmp(raspuns, "da") == 0 || strcmp(raspuns, "DA") == 0)
        {
            cout << "Continuati" << endl;
            continuati = true;
        }
        else
        {
            continuati = false;
        }
    } while (continuati == true);
    clienti->printClientiNota();
}

bool Interactions(Meniu *meniu[], Mese *masa, Clienti *clienti)
{
    cout << endl;
    cout << "Introduceti actiunea dorita: " << endl;
    cout << "1. Meniu" << endl;
    cout << "2. Adauga clienti" << endl;
    cout << "3. Comanda" << endl;
    cout << "4. Cere nota individuala" << endl;
    cout << "5. Cere nota grup" << endl;
    cout << "6. Afisare clienti" << endl;
    cout << "7. Afisare mese" << endl;
    cout << "8. Inchidere restaurant" << endl;
    cout << endl;

    int optiune;
    cin >> optiune;
    switch (optiune)
    {
    case 1:
    {
        for (int i = 0; i < 18; i++)
        {
            meniu[i]->printMeniu();
            if (i == 2 or i == 6 or i == 9 or i == 15)
                cout << endl;
        }
        cout << endl;
        return true;
    }
    case 2:
    {
        AdaugaClienti(masa, clienti);
        return true;
    }
    case 3:
    {

        Comanda(meniu, masa, clienti);

        return true;
    }
    case 4:
    {
        cout << "Introduceti numarul mesei" << endl;
        int nrmasa;
        cin >> nrmasa;
        cout << "Introduceti Id-ul dumneavoastra: " << endl;
        int id;
        cin >> id;
        try
        {
            clienti->verifyClient(id, nrmasa);
        }
        catch (const char *msg)
        {
            cout << msg << endl;
            return true;
        }

        int nota = clienti->getNotaIndividuala(id, nrmasa);
        if (nota != 0)
        {
            cout << "Nota dumneavoastra este: " << nota << endl;
            masa->updateNota(nota, nrmasa);
            clienti->updateNotaIndividuala(nota, id, nrmasa);
        }
        else
        {
            cout << "Nu aveti nimic de platit" << endl;
        }
        return true;
    }
    case 5:
    {
        cout << "Introduceti numarul mesei" << endl;
        int nrmasa;
        cin >> nrmasa;
        int nota = masa->getNota(nrmasa);
        if (nota != 0)
        {
            cout << "Nota dumneavoastra este: " << nota << endl;
            masa->updateNota(nota, nrmasa);
            clienti->updateNotaGrup(nrmasa);
        }
        else
        {
            cout << "Nu aveti nimic de platit" << endl;
        }
        return true;
    }
    case 6:
    {
        cout << clienti;
        return true;
    }
    case 7:
    {
        masa->printMese();
        return true;
    }
    case 8:
    {
        cout << "Ne pare rau pentru discomfortul creat, dar restaurantul nostru trebuie sa se inchida, va asteptam cu drag data viitoare!" << endl;
        return false;
    }
    }
    return true;
}
int main()
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

    Clienti *clienti = new Clienti();
    Mese *masa = new Mese();

    NrMese(masa);
    cout << "Primeste primii clienti in restaurantul nostru!" << endl;
    AdaugaClienti(masa, clienti);

    while (Interactions(meniu, masa, clienti))
    {
        int continuati;
        cout << "Doriti sa continuati? 1/0" << endl;
        cin >> continuati;
        if (continuati == 0)
        {
            break;
        }
    }
    return 0;
}