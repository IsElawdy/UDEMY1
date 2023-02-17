#include <iostream>
#include <math.h> // fuer sqrt
using namespace std;

// Struktur bestehend aus x und y Koordinaten
struct Punkt
{
    float x, y;
};

int main()
{
    // Variablen fuer zwei Punkte
    Punkt p1, p2;
    cout << "x Koordinate von Punkt 1:" << endl;
    cin >> p1.x;
    cout << "y Koordinate von Punkt 1:" << endl;
    cin >> p1.y;
    cout << "x Koordinaten von Punkt 2:" << endl;
    cin >> p2.x;
    cout << "y Koordinaten von Punkt 2:" << endl;
    cin >> p2.y;
    // sqrt : Quadratwurzelfunktion ; Pythagoras
    cout << "Abstand betraegt " << sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) << endl;
    return 0;
}