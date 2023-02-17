#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int matnr;
};
int main()
{ // Feld das die Daten von 30 Einschreibungen aufnehmen kann
    Student studentDaten[30];
    // Anzahl der bereits eingeschriebenen Studenten
    int anzahl = 0;
    // Schleife die solange laeuft, bis der Nutzer n eingibt
    // bei der Abfrage ob er noch weitere Daten eingeben will
    char yn = 'y';
    while (yn == 'y')
    { // wenn bereits anzahl Studenten eingetragen sind,
        // ist bei Index anzahl gerade das erste freie Datenfeld
        cout << "Name und Matrikelnummer eingeben " << endl;
        cin >> studentDaten[anzahl].name;
        cin >> studentDaten[anzahl].matnr;
        // Anzahl anpassen
        anzahl++;
        // Nutzer fragen ob weitere Daten folgen (nur wenn Anzahl kleiner 30)
        if (anzahl < 30)
        {
            cout << "weitere Einschreibungen (y/n) ";
            cin >> yn;
        }
        else // d.h. weiter laufen bzw. neuer Student einschreiben
        {
            yn = 'n';
        }
    }
    // Daten ausgeben
    cout << endl
         << "Einschreibungen: " << endl;
    for (int i = 0; i < anzahl; i++)
    {
        cout << studentDaten[i].name << " " << studentDaten[i].matnr << endl;
    }
    return 0;
}
