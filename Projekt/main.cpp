#include <iostream>                     // Do³¹czenie biblioteki iostream, która umo¿liwia operacje wejœcia/wyjœcia.
#include <locale>                       // Do³¹czenie biblioteki locale

using namespace std;                    // U¿ycie przestrzeni nazw std.


class Figura                            // Utworzenie klasy abstrakcyjnej Figura z jedn¹ publiczn¹ wirtualn¹ bezparametrow¹ metod¹ rysuj().
{
public:                                 // Sekcja publiczna - zawiera publiczne sk³adowe klasy Figura
    virtual void rysuj() = 0;           // Wirtualna bezparametrowa metoda rysuj()
};
//Klasa Kolo, Kwadrat i Trojkat dziedzicz¹ publicznie po klasie Figura i implementuj¹ metodê rysuj():
class Kolo : public Figura              // Klasa Ko³o dziedzicz¹ca po klasie Figura
{
public:                                 // Sekcja publiczna
    void rysuj() override               // Implementacja metody rysuj() dla Ko³a
    {
        cout << "To jest kolo: ()" << endl;       // Rysujê figure Ko³o
    }
};


class Kwadrat : public Figura           // Klasa Kwadrat dziedzicz¹ca po klasie Figura
{
public:                                 // Sekcja publiczna
    void rysuj() override               // Implementacja metody rysuj() dla Kwadratu
    {
        cout << "To jest kwadrat: []" << endl;    // Rysujê figure Kwadrat
    }
};

class Trojkat : public Figura           // Klasa Trójk¹t dziedzicz¹ca po klasie Figura
{
public:
    void rysuj() override               // Implementacja metody rysuj() dla Trójk¹ta
    {
        cout << "To jest trojkat: /_\\" << endl;  // Rysujê figure trójk¹t
    }
};

int main()                              // G³ówna funkcja programu.
{

    // Tworzenie dynamicznych obiektów Ko³o, Kwadrat i Trójk¹t:
    Figura* figura1 = new Kolo();       // Tworzenie obiektu figury 1 jako wskaŸnik na typ Kolo
    Figura* figura2 = new Kwadrat();    // Tworzenie obiektu figury 2 jako wskaŸnik na typ Kwadrat
    Figura* figura3 = new Trojkat();    // Tworzenie obiektu figury 3 jako wskaŸnik na typ Trojkat

    // Wywo³anie metody rysuj() dla ka¿dego obiektu:
    figura1->rysuj();                   // Wywo³anie metody rysuj() dla obiektu figura1
    figura2->rysuj();                   // Wywo³anie metody rysuj() dla obiektu figura2
    figura3->rysuj();                   // Wywo³anie metody rysuj() dla obiektu figura3

    // Usuniêcie obiektów z pamiêci za pomoc¹ operatora delete:
    delete figura1;                     // Zwolnienie pamiêci obiektu figura1
    delete figura2;                     // Zwolnienie pamiêci obiektu figura2
    delete figura3;                     // Zwolnienie pamiêci obiektu figura3

    return 0;                           // Zwrócenie wartoœci 0 - oznacza sukcesowe zakoñczenie programu.
}
