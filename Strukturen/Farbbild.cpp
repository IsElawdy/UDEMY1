#include <iostream>
using namespace std;

struct pixel
{
    int rot, gruen, blau; // rot, gelb, blau
};

int main()
{
    pixel farbbild[10][10];
    /*
     * Beispieldaten einfuegen
     * Nur zun Test des Programms, Belegung mit Daten war nich Teil der Aufgabenstellung
     */
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            farbbild[i][j].rot = (i % 2) * 255;
            cout.width(4);
            cout << farbbild[i][j].rot;
            farbbild[i][j].gruen = ((j / 2) % 2) * 255;
            cout.width(4);
            cout << farbbild[i][j].gruen;
            farbbild[i][j].blau = ((i / 2 + j) % 2) * 255;
            cout.width(4);
            cout << farbbild[i][j].blau;
        }
        cout << endl;
    }

    // Anzahl weisser und schwarzer Punkte zaehlen
    int weiss = 0, schwarz = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (farbbild[i][j].rot == 255 && farbbild[i][j].gruen == 255 && farbbild[i][j].blau == 255)
                weiss++;
            if (farbbild[i][j].rot == 0 && farbbild[i][j].gruen == 0 && farbbild[i][j].blau == 0)
                schwarz++;
        }
    }

    cout << "Anzahl weisser Punkte: " << weiss << endl;
    cout << "Anzahl schwarzer Punkte: " << schwarz << endl;

    return 0;
}
