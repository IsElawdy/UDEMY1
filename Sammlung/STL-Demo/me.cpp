// Beispiel fuer Menge (set)
#include<set>
#include "showseq.h"

int main()
{
    int i;
    set<int> Menge;  // Vergleichsobjekt:  less<int>()

    for(i = 0; i < 10; i++) Menge.insert(i);
    for(i = 0; i < 10; i++) Menge.insert(i); // ohne Wirkung
    showSequence(Menge);                     // 0 1 2 3 4 5 6 7 8 9

/*
Die Anzeige demonstriert, daß die Elemente der Menge wirklich genau
einmal vorkommen. Im folgenden werden Elemente geloescht, wobei in 
der ersten Variante zunaechst das Element gesucht wird, um
es dann mit dem gefundenen Iterator zu loeschen. In der zweiten 
Variante wird die Loeschung ueber den angegebenen Schlüssel 
vorgenommen. 
*/ 

cout << "Loeschen per Iterator\n"
            "Welches Element loeschen? (0..9)" ;
    cin >> i;
    set<int>::iterator iter = Menge.find(i);
    if(iter == Menge.end())
       cout << i << " nicht gefunden!\n";
    else
    {
        cout << "Es gibt " << Menge.count(i)            // 1
             << "-mal das Element " << i << endl;
        Menge.erase(iter);
        cout << i << " geloescht!\n";
        cout << "Es gibt " << Menge.count(i)            // 0
             << "-mal das Element " << i << endl;
    }
    showSequence(Menge);
}
