// aus:
// Breymann, U.: C++ Einfuehrung und professionelle Programmierung
// Muenchen, Wien: Hanser-Verlag, 7. Auflage (2003)
//

#include<iostream>
#include<string>     // Standard-String einschlieﬂen
#include<cstddef>    // size_t 
using namespace std;

int main() {         // Programm mit typischen String-Operationen
    // String-Objekt  einString anlegen und mit  hallo initialisieren.
    // einString kann ein beliebiger Name sein.
    string einString("hallo");

    // String ausgeben
    cout << einString << endl;

       // Beim Vektor w‰re stattdessen f¸r die Ausgabe
      //  eine Schleife notwendig, etwa der folgenden Art:

    for(size_t i = 0; i < einString.size(); ++i)
       cout << einString[i];
    cout << endl;

    // String zeichenweise mit Indexpr¸fung ausgeben. Die Anzahl der
    // Zeichen kann bei Strings auch mit length() ermittelt werden.
    for(size_t i = 0; i < einString.length(); ++i)
       cout << einString.at(i);
    cout << endl;

    // Kopie des Strings einString erzeugen
    string eineStringKopie(einString);
    cout << eineStringKopie << endl;     // hallo

    // Kopie durch Zuweisung
    string diesIstNeu("neu!");
    eineStringKopie = diesIstNeu;
    cout << eineStringKopie << endl;     // neu!

    // Zuweisung einer Zeichenkette in Anf¸hrungszeichen
    eineStringKopie = "Buchstaben";
    cout << eineStringKopie << endl;     // Buchstaben

    // Zuweisung nur eines Zeichens vom Typ  char
    einString = 'X';
    cout << einString << endl;           // X

    // Strings mit dem +=-Operator verketten
    einString += eineStringKopie;
    cout << einString << endl;           // XBuchstaben

    // Strings mit dem  +-Operator verketten
    einString = eineStringKopie + " ABC";
    cout << einString<< endl;           // Buchstaben ABC

    einString = "123" + eineStringKopie;
    cout << einString << endl;           // 123Buchstaben
    string::size_type pos = einString.find("BU");
    cout << "Position von BU : " << pos << '\n';
    pos = einString.find("Bu");
    cout << "Position von Bu : " << pos << '\n';

    // Eine Erkl‰rung gibts erst im Kapitel Ueberladen von Operatoren,
    // aber folgendes geht  nicht:
//    einString = "123" + "ABC";          // Fehler!

      string a("Albert"), z("Alberta");
      string b = a;
      if(a == b) cout << a << " == " << b << endl;
      else       cout << a << " != " << b << endl;
      if(a < z)  cout << a << " < " << z << endl;
      if(z > a)  cout << z << " > " << a << endl;
      if(z != a) cout << z << " != " << a << endl;
}
