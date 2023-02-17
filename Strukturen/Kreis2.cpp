#include <iostream>
#include <math.h>
using namespace std;

struct Punkt
{
    float x, y;
};

struct Kreis
{
    Punkt m; // Mittelpunkt
    float r; // Radius
};

int main()
{
    // Variablen fuer den Punkt und den Kreis
    Kreis k;
    Punkt p;

    cout << "Koordinaten des Kreismittelpunkts: " << endl;
    cin >> k.m.x;
    cin >> k.m.y;

    cout << "Kreisradius: " << endl;
    cin >> k.r;

    cout << "Koordinaten des Punktes: " << endl;
    cin >> p.x;
    cin >> p.y;

    // Abstand zwischen Kreismittelpunkt und dem Punkt
    float d = sqrt((k.m.x - p.x) * (k.m.x - p.x) + (k.m.y - p.y) * (k.m.y - p.y));

    if (d <= k.r)
    {
        cout << "Punkt liegt im Kreis " << endl;
    }
    else
    {
        cout << "Punkt liegt nicht im Kreis " << endl;
    }

    return 0;
}