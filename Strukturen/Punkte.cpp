#include <iostream>
#include <math.h>
using namespace std;

struct Punkt
{
    float x, y;
};

int main()
{
    // Feld bestehend aus 10 Punkten
    Punkt punkte[10];

    // Punkte einlesen
    for (int i = 0; i < 10; i++)
    {
        cout << "Koordinaten von Punkt " << i << endl;
        cin >> punkte[i].x >> punkte[i].y;
    }

    // Punkt am naechsten bzw am weitesten vom Ursprung
    Punkt pmin, pmax;
    pmin.x = punkte[0].x;
    pmin.y = punkte[0].y;
    pmax.x = punkte[0].x;
    pmax.y = punkte[0].y;

    float dmin = sqrt(pmin.x * pmin.x + pmin.y * pmin.y);
    float dmax = sqrt(pmax.x * pmax.x + pmax.y * pmax.y);
    float d;

    for (int i = 0; i < 10; i++)
    {
        d = sqrt(punkte[i].x * punkte[i].x + punkte[i].y * punkte[i].y);
        if (d < dmin)
        {
            dmin = d;
            pmin.x = punkte[i].x;
            pmin.y = punkte[i].y;
        }
        if (d > dmax)
        {
            dmax = d;
            pmax.x = punkte[i].x;
            pmax.y = punkte[i].y;
        }
    }

    cout << "Punkt am naechsten zum Ursprung: (" << pmin.x << "," << pmin.y << ")" << endl;
    cout << "Punkt am entferntesten zum Ursprung: (" << pmax.x << "," << pmax.y << ")" << endl;

    return 0;
}