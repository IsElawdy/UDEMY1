#include <iostream>
using namespace std;

struct dreieck
{
    int laenge;
    int bereite;
};

struct dreieck_2
{
    int laenge = 3;
    int bereite = 2;
};

struct car
{
    string farbe;
    int max_v;
    int min_v;
};

int main()
{

    /******erste Variante******/

    struct dreieck r; // declaration
    int x = r.bereite = 4;
    int y = r.laenge = 2;
    int flaeche = x * y;
    cout << flaeche << endl;
    cout << r.laenge * r.bereite << endl; // aber vorher die Variable Werte geben.

    /******zweite Variante************/
    struct dreieck f = {2, 4}; // declaration + initalisation
    int flache = f.bereite * f.laenge;
    cout << flache << endl;
    /*********dritte Variante*******************/
    // in Struct-Funktion selbst hat die Variable Werte bekommen (struct dreieck_2)
    struct dreieck_2 d;
    cout << d.bereite * d.laenge << endl;
    /**********array of structures**********/
    struct car cars[10] = {{"rot", 100, 50}, {"blau", 120, 70}, {"black", 200, 30}};
    for (int i = 0; i < 3; i++)
    {
        cout << cars[i].farbe << endl;
        cout << cars[i].max_v << endl;
        cout << cars[i].min_v << endl;
    }

    return 0;
}