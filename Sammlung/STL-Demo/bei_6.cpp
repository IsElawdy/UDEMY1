// Beispiel f�r Abbildung (map)
#include<map>
#include<string>

// zur Abk�rzung zwei typedefs
// Vergleichsobjekt:  less<long>()
struct stud{
     string Name, Vorname;
     string Fach;
     int Noten[10];
};

typedef map<long, string> Abbildungstyp;
typedef Abbildungstyp::value_type Wertepaar;


int main()
{
    Abbildungstyp Abbildung;
    Abbildung.insert( Wertepaar(274635328, "Bernd"));
    Abbildung.insert( Wertepaar(260736622, "J�rgen"));
    Abbildung.insert( Wertepaar(720002287, "Karin"));
    Abbildung.insert( Wertepaar(138373498, "Thomas"));
    Abbildung.insert( Wertepaar(135353630, "Uwe"));
    // Einf�gen von Xaver wird nicht ausgef�hrt, weil
    //   der   Schl�ssel schon vorhanden ist.
    Abbildung.insert( Wertepaar(720002287, "Xaver"));

/* 

Die Ausgabe der Namen ist wegen der unterliegenden Implementierung nach Nummern sortiert: 

*/ 

cout << "Ausgabe:\n";
    Abbildungstyp::iterator iter = Abbildung.begin();
    while(iter != Abbildung.end())
    {
          cout << (*iter).first << ':' 
               << (*iter).second  << endl;    
          ++iter;
    }

/*
    cout << "Ausgabe des Namens nach Eingabe der Nummer\n"
         << "Nummer: ";
    long Nummer;
    cin >> Nummer;
    iter = Abbildung.find(Nummer);    // O(log N), siehe Text


    if(iter != Abbildung.end())
        cout << (*iter).second << ' ' // O(1)
             << Abbildung[Nummer]     // O(log N)
             << endl;
    else cout << "Nicht gefunden!" << endl;
*/
}
