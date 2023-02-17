#include <iostream>
#include <string.h> //für strcpy

using namespace std;

struct kind
{
    int gebjahr;
    char land[4]; // Array-Größe 4, da wir max. 4 Plätze brauche
    // und auch nötig für strycpy() zu funktionieren.
    // es reicht im Prinzp nur 1 platz für unser Besipel
    bool lieb;
};

int main()
{
    kind pippilotta;
    pippilotta.gebjahr = 1941;
    string x = strcpy(pippilotta.land, "S"); // d.h. "S" in pippilotta.land kopieren
    pippilotta.lieb = true;                  // o/p: 1
    cout << pippilotta.gebjahr << pippilotta.lieb << endl;
    cout << x << endl;

    return 0;
}