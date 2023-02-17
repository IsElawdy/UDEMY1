#include <iostream>
using namespace std;
int lego(int a)
{
    if (a == 1)
    {
        return 1;
    }
    else
    {
        // int x = a + lego(a - 1); für Debuggen
        // return x;
        return a + lego(a - 1);
        // Es wird bei erste Runde bei lego (1-1) beendet, dann beginnt wieder von unten,also a= 2 dann 3 dann 4.
    }
}
int main(void)
{
    int a, anz = 0;
    cout << "Bitte Hoehe der Treppe eingeben" << endl;
    cin >> a;
    cout << "Die Treppe besteht aus " << lego(a) << " Legosteinen." << endl;
    return 0;
}