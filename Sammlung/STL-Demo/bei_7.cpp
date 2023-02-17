// Beispiel für Menge (set)
#include<set>
#include "showseq.h"


int main()
{
    int i;
    multiset<int> Menge;  // Vergleichsobjekt:  less<int>()


    for(i = 0; i < 10; i++) Menge.insert(20);
    for(i = 0; i < 10; i++) Menge.insert(i*10); // ohne Wirkung
    showSequence(Menge);                     // 0 1 2 3 4 5 6 7 8 9

/*

Die Anzeige demonstriert, daß die Elemente der Menge wirklich genau einmal vorkommen. Im folgenden werden Elemente gelöscht, wobei in der ersten Variante zunächst das Element gesucht wird, um
es dann mit dem gefundenen Iterator zu löschen. In der zweiten Variante wird die Löschung über den angegebenen Schlüssel vorgenommen. 

*/ 

cout << "Löschen per Iterator\n"
            "Welches Element löschen? (0..9)" ;
    cin >> i;
    set<int>::iterator iter = Menge.find(i);
    if(iter == Menge.end())
       cout << i << " nicht gefunden!\n";
    else
    {
        cout << "Es gibt " << Menge.count(i)            // 1
             << "-mal das Element " << i << endl;
        Menge.erase(iter);
        cout << i << " gelöscht!\n";
        cout << "Es gibt " << Menge.count(i)            // 0
             << "-mal das Element " << i << endl;
    }
    showSequence(Menge);

/*

Die Methode count() liefert entweder 0 oder 1. Sie ist damit ein Indikator, ob ein Element in der Menge vorhanden ist.

*/

cout << "Löschen per Wert\n"
            "Welches Element löschen? (0..9)" ;
    cin >> i;
    int Anzahl = Menge.erase(i);
    if(Anzahl == 0)
       cout << i << " nicht gefunden!\n";
    showSequence(Menge);

/* 
Eine weitere Menge Zahlenfolge wird nicht mit einer Schleife initialisiert, sondern durch Angabe des zu übernehmenden Bereichs im Konstruktor. Als Iterator für int-Werte eignen sich Zeiger vom
Typ int*. Der Name eines C-Arrays kann als konstanter Zeiger auf den Arrayanfang aufgefaßt werden. Wenn auf diesen Zeiger die Anzahl der Arrayelemente addiert wird, erhält man einen Zeiger,
der auf die Position nach dem letzten Arrayelement zeigt. Beide Zeiger können als Iteratoren für die Initialisierung einer Menge verwendet werden: 
*/ 

cout << "Konstruktor mit Iteratorbereich aufrufen\n";

    // 2 und 1 doppelt!
    int Feld[] = { 1, 2, 2, 3, 4, 9, 13, 1, 0, 5};
    Anzahl = sizeof(Feld)/sizeof(Feld[0]);

    set<int> Zahlenmenge(Feld, Feld + Anzahl);
    showSequence(Zahlenmenge);    // 0 1 2 3 4 5 9 13
}
