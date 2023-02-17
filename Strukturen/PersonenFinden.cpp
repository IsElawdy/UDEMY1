#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Eintrag
{
    string name;
    int alter;
    int telnummer;
};
int main()
{
    const int N = 8;
    Eintrag tbuch[N];
    int anzahl = 0;
    // Dateieingabe
    ifstream datei;
    datei.open("telefonbuch.txt");
    if (datei.fail())
    {
        cout << "Fehler : telefonbuch,txt nicht geoeffnet" << endl;
        return 0;
    }
    while (datei.eof() == false && anzahl < N)
    {
        datei >> tbuch[anzahl].name;
        datei >> tbuch[anzahl].alter;
        datei >> tbuch[anzahl].telnummer;
        anzahl++;
    }
    datei.close();
    char yn;
    do
    {
        string name;
        cout << "Suche nach Name: ";
        cin >> name;
        int index = -1; //-1 bedeutet nicht gefunden
        for (int i = 0; i < anzahl; i++)
        {
            if (tbuch[i].name == name)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "kein Eintrag gefunden" << endl;
        }
        else
        {
            cout << "Eintrag gefunden" << endl;
            cout << "Name : " << tbuch[index].name << endl;
            cout << "Alter : " << tbuch[index].alter << endl;
            cout << "Tel : " << tbuch[index].telnummer << endl;
        }
        cout << "weitere Anfragen (y/n";
        cin >> yn;
    } while (yn == 'y');
}