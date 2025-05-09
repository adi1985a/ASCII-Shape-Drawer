#include <iostream>                     // Do��czenie biblioteki iostream, kt�ra umo�liwia operacje wej�cia/wyj�cia.
#include <locale>                       // Do��czenie biblioteki locale

using namespace std;                    // U�ycie przestrzeni nazw std.


class Figura                            // Utworzenie klasy abstrakcyjnej Figura z jedn� publiczn� wirtualn� bezparametrow� metod� rysuj().
{
public:                                 // Sekcja publiczna - zawiera publiczne sk�adowe klasy Figura
    virtual void rysuj() = 0;           // Wirtualna bezparametrowa metoda rysuj()
};
//Klasa Kolo, Kwadrat i Trojkat dziedzicz� publicznie po klasie Figura i implementuj� metod� rysuj():
class Kolo : public Figura              // Klasa Ko�o dziedzicz�ca po klasie Figura
{
public:                                 // Sekcja publiczna
    void rysuj() override               // Implementacja metody rysuj() dla Ko�a
    {
        cout << "To jest kolo: ()" << endl;       // Rysuj� figure Ko�o
    }
};


class Kwadrat : public Figura           // Klasa Kwadrat dziedzicz�ca po klasie Figura
{
public:                                 // Sekcja publiczna
    void rysuj() override               // Implementacja metody rysuj() dla Kwadratu
    {
        cout << "To jest kwadrat: []" << endl;    // Rysuj� figure Kwadrat
    }
};

class Trojkat : public Figura           // Klasa Tr�jk�t dziedzicz�ca po klasie Figura
{
public:
    void rysuj() override               // Implementacja metody rysuj() dla Tr�jk�ta
    {
        cout << "To jest trojkat: /_\\" << endl;  // Rysuj� figure tr�jk�t
    }
};

int main()                              // G��wna funkcja programu.
{

    // Tworzenie dynamicznych obiekt�w Ko�o, Kwadrat i Tr�jk�t:
    Figura* figura1 = new Kolo();       // Tworzenie obiektu figury 1 jako wska�nik na typ Kolo
    Figura* figura2 = new Kwadrat();    // Tworzenie obiektu figury 2 jako wska�nik na typ Kwadrat
    Figura* figura3 = new Trojkat();    // Tworzenie obiektu figury 3 jako wska�nik na typ Trojkat

    // Wywo�anie metody rysuj() dla ka�dego obiektu:
    figura1->rysuj();                   // Wywo�anie metody rysuj() dla obiektu figura1
    figura2->rysuj();                   // Wywo�anie metody rysuj() dla obiektu figura2
    figura3->rysuj();                   // Wywo�anie metody rysuj() dla obiektu figura3

    // Usuni�cie obiekt�w z pami�ci za pomoc� operatora delete:
    delete figura1;                     // Zwolnienie pami�ci obiektu figura1
    delete figura2;                     // Zwolnienie pami�ci obiektu figura2
    delete figura3;                     // Zwolnienie pami�ci obiektu figura3

    return 0;                           // Zwr�cenie warto�ci 0 - oznacza sukcesowe zako�czenie programu.
}
