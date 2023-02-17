// Tuerme von Hanoi "Beispiel zur Rekursion (Tuerme von Hanoi) komplexe Datenstruktur"
// Hanoi.cpp
#include <iostream>
using namespace std;

const int MAX = 20;
int zug = 1; // Nr. des Zuges

enum
{
    start,
    ziel,
    hilfe
}; // "Namen" der drei Stapel

struct
{
    int anz;
    int scheiben[MAX];
} stapel[3]; // die drei Stapel

int eingabe() // Eingabe der Scheibenzahl, belegen Startstapel
{
    int i = 0, anz;
    do
    {
        cout << "Anzahl Scheiben: ";
        cin >> anz;
    } while (anz < 1 || anz > MAX);
    stapel[start].anz = anz;
    stapel[ziel].anz = stapel[hilfe].anz = 0;

    while (anz)
        stapel[start].scheiben[i++] = anz--;

    return stapel[start].anz;
}

void protokoll(int i) // Ausgabe des Stapelnamens als Text
{
    switch (i)
    {
    case start:
        cout << "Start";
        break;
    case hilfe:
        cout << "Hilfe";
        break;
    case ziel:
        cout << "Ziel ";
        break;
    }
}

void verschiebe(int von, int nach) // Verschieben der obersten Scheibe
{
    stapel[nach].scheiben[stapel[nach].anz++] =
        stapel[von].scheiben[--stapel[von].anz];
    cout << zug++ << ": ";
    protokoll(von);
    cout << " --> ";
    protokoll(nach);
    cout << endl;
}

void hanoi(int n, int von, int nach, int mit) // Loesen der Aufgabe
{
    if (n > 0)
    {
        hanoi(n - 1, von, mit, nach);
        verschiebe(von, nach);
        hanoi(n - 1, mit, nach, von);
    }
}

int main(void)
{
    cout << endl
         << "Turm von Hanoi" << endl
         << endl;
    hanoi(eingabe(), start, ziel, hilfe);
    return 0;
}